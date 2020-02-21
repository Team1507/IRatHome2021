#pragma once

#include <frc/commands/Command.h>

class CmdAdjustHood : public frc::Command {
 public:
  CmdAdjustHood(int angle);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
  int m_angle;
};
