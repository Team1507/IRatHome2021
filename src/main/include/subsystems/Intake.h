#pragma once

#include <frc/commands/Subsystem.h>

class Intake : public frc::Subsystem {
 private:
//ThIs Is wHeRe ViCtOr GoEs.
 public:
    Intake();
    void InitDefaultCommand() override;
    void IntakeForward(void);
    void IntakeStop(void);    
    void IntakeBackward(void);

};  
