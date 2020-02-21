#include "commands/CmdAdjustHood.h"
#include "Robot.h"
CmdAdjustHood::CmdAdjustHood(int angle) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  m_angle = angle;
}

void CmdAdjustHood::Initialize() 
{
  Robot::m_shooter.SetHood(m_angle);
}

void CmdAdjustHood::Execute() {}

bool CmdAdjustHood::IsFinished() { return true; }

void CmdAdjustHood::End() {}

void CmdAdjustHood::Interrupted() {}
