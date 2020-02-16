#pragma once

#include <frc/commands/Command.h>

class CmdSpinControlPanelToColor : public frc::Command {
    private:

    double m_color;
    double m_wantedColor;
    bool   m_onColor;

    public:
    CmdSpinControlPanelToColor( double wantedColor );
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};
