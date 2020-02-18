#pragma once

#include <frc/commands/Command.h>

class CmdSpin3Times : public frc::Command {
    private:
    bool   m_isGreen;
    bool   m_isYellow;
    bool   m_isRed;
    bool   m_isBlue;
    double m_spins;
    double m_color;
    int m_numberGreenTruecounts;
    int m_numberGreenFalsecounts;
    int m_numberRedTruecounts;
    int m_numberRedFalsecounts;
    int m_numberYellowTruecounts;
    int m_numberYellowFalsecounts;
    int m_numberBlueTruecounts;
    int m_numberBlueFalsecounts;
 public:
  CmdSpin3Times();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
