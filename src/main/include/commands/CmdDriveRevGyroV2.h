

#pragma once

#include <frc/commands/Command.h>

class CmdDriveRevGyroV2 : public frc::Command {
 public:
    CmdDriveRevGyroV2(double power, double heading, double distance, bool ramp, bool stop, double timeout);
    
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;


  private:
    double m_power;
    double m_heading;
    double m_distance;
    bool   m_stop;
    double m_timeout;   

    bool   m_ramp;
    double m_base;

};
