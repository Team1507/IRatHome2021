#pragma once

#include <frc/commands/Command.h>

class CmdStopShooter : public frc::Command {
 public:
  CmdStopShooter();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
