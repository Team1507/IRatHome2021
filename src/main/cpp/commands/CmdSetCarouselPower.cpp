#include "commands/CmdSetCarouselPower.h"
#include "subsystems/Shooter.h"
#include "Robot.h"


CmdSetCarouselPower::CmdSetCarouselPower( double power ) 
{
  m_power = power;
}

void CmdSetCarouselPower::Initialize() 
{
  frc::SmartDashboard::PutNumber("Carousel Power", 0);
  //Robot::m_shooter.SetCarouselPower( m_power );
}

void CmdSetCarouselPower::Execute()
{

  double power = frc::SmartDashboard::GetNumber("Carousel Power", 0);
  Robot::m_shooter.SetCarouselPower( power );
}



bool CmdSetCarouselPower::IsFinished() { return false; }

void CmdSetCarouselPower::End() {}

void CmdSetCarouselPower::Interrupted() {}
