#pragma once
#include <frc/Servo.h>
#include <frc/commands/Subsystem.h>

class BallDeflector : public frc::Subsystem {
 private:
 
  frc::Servo m_linearActuator {0};
 public:
  BallDeflector();
  void InitDefaultCommand() override;
  void DeployDeflector();
  void RetractDeflector();
};
