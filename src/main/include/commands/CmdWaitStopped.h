

#pragma once

#include <frc/commands/Command.h>

class CmdWaitStopped : public frc::Command {
 public:
    CmdWaitStopped(double timeout);
    
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;


  private:

    double m_timeout;   

};
