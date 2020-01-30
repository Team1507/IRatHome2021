#include "commands/CmdSetShooterVelocity.h"
#include "subsystems/Shooter.h"
#include "Robot.h"

CmdSetShooterVelocity::CmdSetShooterVelocity( double rpm ) {
  // eg. Requires(Robot::chassis.get());
  m_rpm = rpm;
}

void CmdSetShooterVelocity::Initialize() 
{
  Robot::m_shooter.SetShooterVelocity(m_rpm);
}

void CmdSetShooterVelocity::Execute() {}

bool CmdSetShooterVelocity::IsFinished() { return true; }

void CmdSetShooterVelocity::End() {}

void CmdSetShooterVelocity::Interrupted() {}
