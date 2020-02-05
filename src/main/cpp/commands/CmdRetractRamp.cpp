
#include "commands/CmdRetractRamp.h"
#include "Robot.h"
#include "subsystems/Shooter.h"
CmdRetractRamp::CmdRetractRamp() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

void CmdRetractRamp::Initialize() 
{
  Robot::m_shooter.RetractRamp();
}

void CmdRetractRamp::Execute() {}

bool CmdRetractRamp::IsFinished() { return true; }

void CmdRetractRamp::End() {}

void CmdRetractRamp::Interrupted() {}

