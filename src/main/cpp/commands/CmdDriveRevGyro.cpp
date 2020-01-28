

#include "Commands\CmdDriveRevGyro.h"
#include "Robot.h"

CmdDriveRevGyro::CmdDriveRevGyro(double power, double heading, double distance, bool stop, double timeout)
{
  m_power    = (-1.0) * power;		//Reverse = negative power
	m_heading  = heading;
  m_distance = (-1.0) * distance;	//Reverse = Negative distance
  m_stop     = stop;
  m_timeout  = timeout;

  // Use Requires() here to declare subsystem dependencies
  Requires( &Robot::m_drivetrain);
}

// Called just before this Command runs the first time
void CmdDriveRevGyro::Initialize() 
{
  Robot::m_drivetrain.ResetEncoders();

	if( m_timeout > 0.0)
	{
		SetTimeout (m_timeout);
	}

}

// Called repeatedly when this Command is scheduled to run
void CmdDriveRevGyro::Execute() 
{
	double errorAngle = Robot::m_drivetrain.GetGyroAngle() - m_heading;
	double kp = 0.02;	//Was 0.04;


	Robot::m_drivetrain.Drive(m_power - errorAngle*kp  ,  m_power + errorAngle*kp ); 
	//Robot::m_drivetrain->DriveAcc(m_power - errorAngle*kp  ,  m_power + errorAngle*kp ); 
}

// Make this return true when this Command no longer needs to run execute()
bool CmdDriveRevGyro::IsFinished() 
{
	double l_dir = Robot::m_drivetrain.GetLeftEncoder()/Drivetrain::LEFT_ENCODER_TPI;
	double r_dir = Robot::m_drivetrain.GetRightEncoder()/Drivetrain::RIGHT_ENCODER_TPI;

	if(  (l_dir < m_distance) || (r_dir < m_distance)  )
	  return true;

	if ((m_timeout>0.0) && IsTimedOut())
	{
		std::cout<<"CmdDriveRevGyro: Timeout"<<std::endl;
		return true;
	}

	return false;
}

// Called once after isFinished returns true
void CmdDriveRevGyro::End() 
{
  if(m_stop)
	{
		Robot::m_drivetrain.Stop();
	}
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdDriveRevGyro::Interrupted() 
{
  End();
}
