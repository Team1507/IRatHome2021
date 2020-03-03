#include "Robot.h"
#include <iostream>
#include "ctre/Phoenix.h"
#include "subsystems/DriverFeedback.h"
#include <frc/GenericHID.h>

#include "subsystems/DriverFeedback.h"

DriverFeedback::DriverFeedback() : Subsystem("ExampleSubsystem") {}

void DriverFeedback::InitDefaultCommand() {}

void DriverFeedback::UpdateBotLEDs(float _r, float _g, float _b)
{    
	/* Update CANifier's LED strip */
	//Hardware::
	//Channel A and B is incorrect in documentation
	 
   // m_bot_canifier.SetLEDOutput(_g, CANifier::LEDChannel::LEDChannelA);
	//m_bot_canifier.SetLEDOutput(_r, CANifier::LEDChannel::LEDChannelB);
	//m_bot_canifier.SetLEDOutput(_b, CANifier::LEDChannel::LEDChannelC);
    
}

void DriverFeedback::UpdateTopLEDs(float _r, float _g, float _b)
{   
	/* Update CANifier's LED strip */
	//Hardware::
	//Channel A and B is incorrect in documentation 
   
    // m_top_canifier.SetLEDOutput(_g, CANifier::LEDChannel::LEDChannelA);
	// m_top_canifier.SetLEDOutput(_r, CANifier::LEDChannel::LEDChannelB);
	// m_top_canifier.SetLEDOutput(_b, CANifier::LEDChannel::LEDChannelC);    
    
}

void DriverFeedback::TopLEDsOff(){

    // m_top_canifier.SetLEDOutput(0, CANifier::LEDChannel::LEDChannelA);
	// m_top_canifier.SetLEDOutput(0, CANifier::LEDChannel::LEDChannelB);
	// m_top_canifier.SetLEDOutput(0, CANifier::LEDChannel::LEDChannelC);

}

void DriverFeedback::BotLEDsOff(){

    // m_bot_canifier.SetLEDOutput(0, CANifier::LEDChannel::LEDChannelA);
	// m_bot_canifier.SetLEDOutput(0, CANifier::LEDChannel::LEDChannelB);
	// m_bot_canifier.SetLEDOutput(0, CANifier::LEDChannel::LEDChannelC);  

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