#include "commands/CmdSetShooterVelocity.h"
#include "commands/CmdSetFeederVelocity.h"
#include "Robot.h"
CmdSetFeederVelocity::CmdSetFeederVelocity(double rpm) {
  // Use Requires() here to declare subsystem dependencies


    m_rpm = rpm;
  // eg. Requires(Robot::chassis.get());
}


void CmdSetFeederVelocity::Initialize() {

  Robot::m_shooter.SetFeederVelocity(m_rpm);
}


void CmdSetFeederVelocity::Execute() {}


bool CmdSetFeederVelocity::IsFinished() { return true; }


void CmdSetFeederVelocity::End() {}


void CmdSetFeederVelocity::Interrupted() {}
