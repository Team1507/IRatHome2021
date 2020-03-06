
#include "Commands\CmdWaitStopped.h"
#include "Robot.h"

CmdWaitStopped::CmdWaitStopped(double timeout)
{
  m_timeout  = timeout;

  // Use Requires() here to declare subsystem dependencies
  Requires( &Robot::m_drivetrain);
}

// Called just before this Command runs the first time
void CmdWaitStopped::Initialize() 
{
	SetTimeout (m_timeout);
}

// Called repeatedly when this Command is scheduled to run
void CmdWaitStopped::Execute() 
{
	//Continuously update drivertrain so we don't get MotorSaftey Errors
	Robot::m_drivetrain.Drive(0,0); 
}

// Make this return true when this Command no longer needs to run execute()
bool CmdWaitStopped::IsFinished() 
{
	if ( IsTimedOut() )
	{
		return true;
	}

	return false;
}

// Called once after isFinished returns true
void CmdWaitStopped::End() 
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdWaitStopped::Interrupted() 
{
  End();
}
