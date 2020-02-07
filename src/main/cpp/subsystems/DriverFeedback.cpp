#include "Robot.h"
#include <iostream>
#include "ctre/Phoenix.h"
#include "subsystems/DriverFeedback.h"
#include <frc/GenericHID.h>

#include "subsystems/DriverFeedback.h"

DriverFeedback::DriverFeedback() : Subsystem("ExampleSubsystem") {}

void DriverFeedback::InitDefaultCommand() {}

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