#pragma once

#include <frc/commands/Command.h>

class CmdSetIntake : public frc::Command {
 public:
  CmdSetIntake(bool isRunning);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
  private:
   bool m_isRunning;
};
