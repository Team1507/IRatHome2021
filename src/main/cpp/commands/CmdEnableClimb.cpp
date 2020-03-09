#include "commands/CmdEnableClimb.h"
#include "Robot.h"
CmdEnableClimb::CmdEnableClimb() {}

void CmdEnableClimb::Initialize() 
{
    Robot::m_climber.SetClimbActivated();
}

void CmdEnableClimb::Execute() {}

bool CmdEnableClimb::IsFinished() { return true; }

void CmdEnableClimb::End() {}

void CmdEnableClimb::Interrupted() {}