#pragma once

#include <frc/commands/Command.h>

class CmdEnableClimb : public frc::Command {
 public:
  CmdEnableClimb();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
