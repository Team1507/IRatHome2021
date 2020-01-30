#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"
class Climber : public frc::Subsystem {
 private:
    //WINCH HERE
 public:
  Climber();
  void InitDefaultCommand() override;
  void ExtendLightsaber();
  void RetractLightsaber();
  void UseWinch();
};
