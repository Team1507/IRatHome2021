#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"

class Intake : public frc::Subsystem {
    private:
        WPI_VictorSPX m_intakeMotor{INTAKE_CAN_ID};
    public:
        Intake();
        void InitDefaultCommand() override;
        void IntakeForward(void);
        void IntakeStop(void);    
        void IntakeBackward(void);
};  
