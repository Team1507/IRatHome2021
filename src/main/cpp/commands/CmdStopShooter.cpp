#include "commands/CmdStopShooter.h"
#include "subsystems/Shooter.h"
#include "Robot.h"

CmdStopShooter::CmdStopShooter() 
{
    Robot::m_shooter.StopShooter();
}

void CmdStopShooter::Initialize() {}

void CmdStopShooter::Execute() {}

bool CmdStopShooter::IsFinished() { return true; }

void CmdStopShooter::End() {}

void CmdStopShooter::Interrupted() {}
