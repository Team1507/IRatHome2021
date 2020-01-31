#pragma once

#include <frc/commands/Command.h>

class CmdTurnToLimelight : public frc::Command {
    private:
        double m_Kp;
        double m_minPower;
        double m_targetAngle;
    public:
        CmdTurnToLimelight();
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
};
