#pragma once

#include <frc/commands/Command.h>

class CmdTest1 : public frc::Command {
 public:
  CmdTest1();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
