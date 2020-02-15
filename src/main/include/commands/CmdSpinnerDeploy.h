#pragma once

#include <frc/commands/Command.h>

class CmdSpinnerDeploy : public frc::Command {
 private:
  bool m_hasTurbo;
  bool m_isMoving;
 public:
  CmdSpinnerDeploy();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
