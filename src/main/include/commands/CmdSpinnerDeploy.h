#pragma once

#include <frc/commands/Command.h>

class CmdSpinnerDeploy : public frc::Command {
 public:
  CmdSpinnerDeploy();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
