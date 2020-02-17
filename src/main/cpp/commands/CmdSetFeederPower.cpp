#include "commands/CmdSetShooterVelocity.h"
#include "commands/CmdSetFeederPower.h"
#include "Robot.h"
CmdSetFeederPower::CmdSetFeederPower(double power) {
  // Use Requires() here to declare subsystem dependencies


    m_power = power;
  // eg. Requires(Robot::chassis.get());
}


void CmdSetFeederPower::Initialize() {

  Robot::m_shooter.SetFeederPower(m_power);
}


void CmdSetFeederPower::Execute() {}


bool CmdSetFeederPower::IsFinished() { return true; }


void CmdSetFeederPower::End() {}


void CmdSetFeederPower::Interrupted() {}
