#include "Robot.h"
#include <iostream>
// #include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include "subsystems/DriverFeedback.h"
#include <frc/GenericHID.h>

#include "subsystems/DriverFeedback.h"

DriverFeedback::DriverFeedback() : Subsystem("ExampleSubsystem") {}

void DriverFeedback::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void DriverFeedback::RumbleOn(void)
{
	Robot::m_oi.GetDriverGamepad()->SetRumble(frc::GenericHID::kLeftRumble, 1);
	Robot::m_oi.GetDriverGamepad()->SetRumble(frc::GenericHID::kRightRumble, 1);

	Robot::m_oi.GetOperatorGamepad()->SetRumble(frc::GenericHID::kLeftRumble, 1);
	Robot::m_oi.GetOperatorGamepad()->SetRumble(frc::GenericHID::kRightRumble, 1);
}

void DriverFeedback::RumbleOff(void)
{
	Robot::m_oi.GetDriverGamepad()->SetRumble(frc::GenericHID::kLeftRumble, 0.0);
	Robot::m_oi.GetDriverGamepad()->SetRumble(frc::GenericHID::kRightRumble, 0.0);

	Robot::m_oi.GetOperatorGamepad()->SetRumble(frc::GenericHID::kLeftRumble, 0.0);
	Robot::m_oi.GetOperatorGamepad()->SetRumble(frc::GenericHID::kRightRumble, 0.0);
}

// frc::SmartDashboard::PutData("Rumble_On ", DriverFeedback::RumbleOn());
// frc::SmartDashboard::PutData("Rumble_Off ", DriverFeedback::RumbleOff());
