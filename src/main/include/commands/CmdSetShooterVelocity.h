#pragma once

#include <frc/commands/Command.h>

class CmdSetShooterVelocity : public frc::Command {
    public:
        CmdSetShooterVelocity( double rpm );
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
    private:
        double m_rpm;
};
