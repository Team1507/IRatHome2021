#pragma once

#include <frc/commands/Command.h>

class CmdShootTest : public frc::Command {
 public:
  CmdShootTest();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
