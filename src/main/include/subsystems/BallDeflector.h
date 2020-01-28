#pragma once

#include <frc/commands/Subsystem.h>

class BallDeflector : public frc::Subsystem {
 private:
 

 public:
  BallDeflector();
  void InitDefaultCommand() override;
  void DeployDeflector();
  void RetractDeflector();
};
