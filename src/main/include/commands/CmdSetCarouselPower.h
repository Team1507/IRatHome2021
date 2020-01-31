#pragma once

#include <frc/commands/Command.h>

class CmdSetCarouselPower : public frc::Command {
    private:

    double m_power;

    public:
        CmdSetCarouselPower( double power );
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
};
