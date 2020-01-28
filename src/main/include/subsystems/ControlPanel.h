#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"

class ControlPanel : public frc::Subsystem {
    private:
        //servo
        WPI_VictorSPX m_controlMotor{CONTROL_MOTOR_CAN_ID};
        //color sensor idek what this is yet
    public:
        ControlPanel();
        void InitDefaultCommand() override;
        void DeployControl(void);
        void RetractControl(void);
        int GetColor(void); //return type not determined (most likely 1 red, 2 green etc...)
        void SpinControl(void);
        void StopControl(void);
};
