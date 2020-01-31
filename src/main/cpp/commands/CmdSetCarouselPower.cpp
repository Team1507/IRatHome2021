#include "commands/CmdSetCarouselPower.h"
#include "subsystems/Shooter.h"
#include "Robot.h"

CmdSetCarouselPower::CmdSetCarouselPower( double power ) 
{
  m_power = power;
}

void CmdSetCarouselPower::Initialize() 
{
  Robot::m_shooter.SetCarouselPower( m_power );
}

void CmdSetCarouselPower::Execute() {}

bool CmdSetCarouselPower::IsFinished() { return true; }

void CmdSetCarouselPower::End() {}

void CmdSetCarouselPower::Interrupted() {}
