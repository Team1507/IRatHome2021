#include "commands/CmdExtendRamp.h"
#include "subsystems/Shooter.h"
#include "Robot.h"

CmdExtendRamp::CmdExtendRamp() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

void CmdExtendRamp::Initialize() 
{
  Robot::m_shooter.ExtendRamp();
}

// Called repeatedly when this Command is scheduled to run
void CmdExtendRamp::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool CmdExtendRamp::IsFinished() { return false; }

// Called once after isFinished returns true
void CmdExtendRamp::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdExtendRamp::Interrupted() {}
