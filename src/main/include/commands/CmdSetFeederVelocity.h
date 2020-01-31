#pragma once

#include <frc/commands/Command.h>

class CmdSetFeederVelocity : public frc::Command {
 private:
  double m_rpm;


 public:
  CmdSetFeederVelocity(double rpm);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
