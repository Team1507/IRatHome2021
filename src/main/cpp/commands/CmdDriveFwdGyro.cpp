#include "Commands\CmdDriveFwdGyro.h"
#include "Robot.h"

CmdDriveFwdGyro::CmdDriveFwdGyro(double power, double heading, double distance, bool stop, double timeout)
{
	m_power    = power;
	m_heading  = heading;
	m_distance = distance;
	m_stop     = stop;
	m_timeout  = timeout;

  // Use Requires() here to declare subsystem dependencies
  Requires( &Robot::m_drivetrain);
}

// Called just before this Command runs the first time
void CmdDriveFwdGyro::Initialize() 
{
  Robot::m_drivetrain.ResetEncoders();

	if( m_timeout > 0.0)
	{
		SetTimeout (m_timeout);
	}

}
//this comment was made at my home -Cory J M, not "ex-Katie's Cory"
// Called repeatedly when this Command is scheduled to run
void CmdDriveFwdGyro::Execute() 
{
	//Don't use GetGyroYaw; if we try to drive on -181 heading, yaw freaks out and goes positive
	//double errorAngle = Robot::m_drivetrain->GetGyroYaw() - m_heading;
	double errorAngle = Robot::m_drivetrain.GetGyroAngle() - m_heading;
	double kp = 0.002; //was 0.05, then 0.04

	Robot::m_drivetrain.Drive(m_power - errorAngle*kp  ,  m_power + errorAngle*kp ); 
}

// Make this return true when this Command no longer needs to run execute()
bool CmdDriveFwdGyro::IsFinished() 
{

	double l_dir = Robot::m_drivetrain.GetLeftEncoder()/Drivetrain::LEFT_ENCODER_TPI;
	double r_dir = Robot::m_drivetrain.GetRightEncoder()/Drivetrain::RIGHT_ENCODER_TPI;

	if(  (l_dir >= m_distance) || (r_dir >= m_distance)  )
	  return true;

	if ((m_timeout>0.0) && IsTimedOut())
	{
		std::cout<<"CmdDriveFwdGyro: Timeout"<<std::endl;
		return true;
	}

	return false;
}

// Called once after isFinished returns true
void CmdDriveFwdGyro::End() 
{
	std::cout<<"CmdDriveFwdGyro: End at  ";
	std::cout<<"   FL ";
	std::cout<<int( Robot::m_drivetrain.GetLeftEncoder()/Drivetrain::LEFT_ENCODER_TPI );
	std::cout<<"   FR ";
	std::cout<<int( Robot::m_drivetrain.GetRightEncoder()/Drivetrain::RIGHT_ENCODER_TPI );
	std::cout<<std::endl;


  	if(m_stop)
	{
		Robot::m_drivetrain.Stop();
	}
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdDriveFwdGyro::Interrupted() 
{
  End();
}
