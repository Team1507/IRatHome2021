#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"
class Climber : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  Climber();
  void InitDefaultCommand() override;
  void ExtendLightsaber();
  void RetractLightsaber();
  void UseWinch();
};
