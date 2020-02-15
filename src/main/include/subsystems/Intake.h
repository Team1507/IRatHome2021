#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"

class Intake : public frc::Subsystem {
    private:
        WPI_VictorSPX m_intakeMotor{INTAKE_CAN_ID};
        bool m_isIntaking = false;
    public:
        Intake();
        void InitDefaultCommand() override;
        void IntakePeriodic(void);
        void IntakeForward(void);
        void IntakeForward(double power);
        void IntakeStop(void);    
        void IntakeBackward(void);
        
};  
