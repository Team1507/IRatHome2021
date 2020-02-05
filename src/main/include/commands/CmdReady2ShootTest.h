#pragma once

#include <frc/commands/Command.h>

class CmdReady2ShootTest : public frc::Command {
 public:
  CmdReady2ShootTest();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
