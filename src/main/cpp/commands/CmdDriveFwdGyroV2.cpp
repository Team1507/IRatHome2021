#include "Commands\CmdDriveFwdGyroV2.h"
#include "Robot.h"

CmdDriveFwdGyroV2::CmdDriveFwdGyroV2(double power, double heading, double distance, bool ramp, bool stop, double timeout)
{
	m_power    = power;
	m_heading  = heading;
	m_distance = distance;
	m_stop     = stop;
	m_timeout  = timeout;

	m_ramp = ramp;
    m_base = 0;

	// Use Requires() here to declare subsystem dependencies
	Requires( &Robot::m_drivetrain);
}

// Called just before this Command runs the first time
void CmdDriveFwdGyroV2::Initialize() 
{
  	Robot::m_drivetrain.ResetEncoders();
	
	m_base = 0.1;	//Initial Power

	if( m_timeout > 0.0)
	{
		SetTimeout (m_timeout);
	}

}


// Called repeatedly when this Command is scheduled to run
void CmdDriveFwdGyroV2::Execute() 
{

	//Ramp base power
	if( m_ramp )
		m_base += (m_power - m_base) * Drivetrain::RAMP_FACTOR;
	else
		m_base = m_power;
	


	//Don't use GetGyroYaw; if we try to drive on -181 heading, yaw freaks out and goes positive
	//double errorAngle = Robot::m_drivetrain->GetGyroYaw() - m_heading;
	double errorAngle = Robot::m_drivetrain.GetGyroAngle() - m_heading;
	double kp = 0.002; //was 0.05, then 0.04

	Robot::m_drivetrain.Drive(m_base - errorAngle*kp  ,  m_base + errorAngle*kp ); 
}

// Make this return true when this Command no longer needs to run execute()
bool CmdDriveFwdGyroV2::IsFinished() 
{

	double l_dir = Robot::m_drivetrain.GetLeftEncoder()/Drivetrain::LEFT_ENCODER_TPI;
	double r_dir = Robot::m_drivetrain.GetRightEncoder()/Drivetrain::RIGHT_ENCODER_TPI;

	if(  (l_dir >= m_distance) || (r_dir >= m_distance)  )
	  return true;

	if ((m_timeout>0.0) && IsTimedOut())
	{
		std::cout<<"CmdDriveFwdGyroV2: Timeout"<<std::endl;
		return true;
	}

	return false;
}

// Called once after isFinished returns true
void CmdDriveFwdGyroV2::End() 
{
	std::cout<<"CmdDriveFwdGyroV2: End at  ";
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
void CmdDriveFwdGyroV2::Interrupted() 
{
  End();
}
