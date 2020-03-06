

#include "Commands\CmdDriveRevGyroV2.h"
#include "Robot.h"

CmdDriveRevGyroV2::CmdDriveRevGyroV2(double power, double heading, double distance, bool ramp, bool stop, double timeout)
{
  	m_power    = (-1.0) * power;		//Reverse = negative power
	m_heading  = heading;
  	m_distance = (-1.0) * distance;	//Reverse = Negative distance
  	m_stop     = stop;
  	m_timeout  = timeout;

	m_ramp = ramp;
    m_base = 0;

	// Use Requires() here to declare subsystem dependencies
	Requires( &Robot::m_drivetrain);
}

// Called just before this Command runs the first time
void CmdDriveRevGyroV2::Initialize() 
{
  	Robot::m_drivetrain.ResetEncoders();

	m_base = -0.05;	//Initial Power

	if( m_timeout > 0.0)
	{
		SetTimeout (m_timeout);
	}

}

// Called repeatedly when this Command is scheduled to run
void CmdDriveRevGyroV2::Execute() 
{

	//Ramp base power
	if( m_ramp )
		m_base += (m_power - m_base) * Drivetrain::RAMP_FACTOR;
	else
		m_base = m_power;


	double errorAngle = Robot::m_drivetrain.GetGyroAngle() - m_heading;
	double kp = 0.02;	//Was 0.04;


	Robot::m_drivetrain.Drive(m_base - errorAngle*kp  ,  m_base + errorAngle*kp ); 

}

// Make this return true when this Command no longer needs to run execute()
bool CmdDriveRevGyroV2::IsFinished() 
{
	double l_dir = Robot::m_drivetrain.GetLeftEncoder()/Drivetrain::LEFT_ENCODER_TPI;
	double r_dir = Robot::m_drivetrain.GetRightEncoder()/Drivetrain::RIGHT_ENCODER_TPI;

	if(  (l_dir <= m_distance) || (r_dir <= m_distance)  )
	  return true;

	if ((m_timeout>0.0) && IsTimedOut())
	{
		std::cout<<"CmdDriveRevGyroV2: Timeout"<<std::endl;
		return true;
	}

	return false;
}

// Called once after isFinished returns true
void CmdDriveRevGyroV2::End() 
{
	std::cout<<"CmdDriveRevGyroV2: End at  ";
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
void CmdDriveRevGyroV2::Interrupted() 
{
  End();
}
