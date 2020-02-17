#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"
class Climber : public frc::Subsystem {
 private:
   WPI_VictorSPX m_leftWinchMotor {LEFT_WINCH_CAN_ID};
   WPI_VictorSPX m_rightWinchMotor{RIGHT_WINCH_CAN_ID};
   WPI_VictorSPX m_lightsaber {LIGHTSABER_CAN_ID};
    
 public:
  Climber();
  void ClimberPeriodic();
  void InitDefaultCommand() override;
  void MoveLightsaber(double power);

};
