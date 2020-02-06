#pragma once

#include <frc/commands/Subsystem.h>

class DriverFeedback : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  DriverFeedback();
  void InitDefaultCommand() override;
  void RumbleOn(void);
  void RumbleOff(void);
};
