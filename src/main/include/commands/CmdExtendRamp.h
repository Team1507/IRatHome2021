#pragma once

#include <frc/commands/Command.h>

class CmdExtendRamp : public frc::Command {
    public:
         CmdExtendRamp();
         void Initialize() override;
         void Execute() override;
         bool IsFinished() override;
         void End() override;
         void Interrupted() override;
};
