
#include "Commands\CmdDriveRevEncoder.h"
#include "Robot.h"

CmdDriveRevEncoder::CmdDriveRevEncoder(double power, double distance, bool stop, double timeout)
{
  m_power    = (-1.0) * power;		//Reverse = negative power
  m_distance = (-1.0) * distance;	//Reverse = Negative distance
  m_stop     = stop;							//stop = true; coast = false
  m_timeout  = timeout;

  // Use Requires() here to declare subsystem dependencies
  Requires( &Robot::m_drivetrain);
}

// Called just before this Command runs the first time
void CmdDriveRevEncoder::Initialize() 
{
  Robot::m_drivetrain.ResetEncoders();

	if( m_timeout > 0.0)
	{
		SetTimeout (m_timeout);
	}

}

// Called repeatedly when this Command is scheduled to run
void CmdDriveRevEncoder::Execute() 
{
 	double l_dir = Robot::m_drivetrain.GetLeftEncoder()/Drivetrain::LEFT_ENCODER_TPI;
	double r_dir = Robot::m_drivetrain.GetRightEncoder()/Drivetrain::RIGHT_ENCODER_TPI;
	double delta = l_dir - r_dir;
	double kp    = -0.03;

	Robot::m_drivetrain.Drive(m_power - delta*kp  ,  m_power + delta*kp ); 
	//Robot::m_drivetrain->DriveAcc(m_power - delta*kp  ,  m_power + delta*kp ); 
}

// Make this return true when this Command no longer needs to run execute()
bool CmdDriveRevEncoder::IsFinished() 
{

	double l_dir = Robot::m_drivetrain.GetLeftEncoder()/Drivetrain::LEFT_ENCODER_TPI;
	double r_dir = Robot::m_drivetrain.GetRightEncoder()/Drivetrain::RIGHT_ENCODER_TPI;

	if(  (l_dir < m_distance) || (r_dir < m_distance)  )
	  return true;

	if ((m_timeout>0.0) && IsTimedOut())
	{
		std::cout<<"CmdDriveRevEncoder: Timeout"<<std::endl;
		return true;
	}

	return false;
}

// Called once after isFinished returns true
void CmdDriveRevEncoder::End() 
{
  if(m_stop)
	{
		Robot::m_drivetrain.Stop();
	}
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdDriveRevEncoder::Interrupted() 
{
  End();
}
