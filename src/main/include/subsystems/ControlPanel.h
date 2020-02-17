#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include <frc/DigitalInput.h>
#include <rev/ColorSensorV3.h>

class ControlPanel : public frc::Subsystem {
    private:
        bool m_isDeployed;

        frc::DigitalInput m_bottomSwitch{1};
        frc::DigitalInput m_topSwitch{0};

        //servo
        WPI_VictorSPX m_deployMotor{CP_DEPLOY_CAN_ID};
        WPI_VictorSPX m_spinnerMotor{CP_SPINNER_CAN_ID};
        //color sensor idek what this is yet
    public:
        ControlPanel();
        void ControlPanelPeriodic();
        void InitDefaultCommand() override;
        bool isTopSwitchPress( void );
        bool isBottomSwitchPress( void );
        bool GetIsDeployed( void );
        void DeployControl(void);
        void RetractControl(void);
        void TURBODeployControl(void);
        void TURBORetractControl(void);
        void StopControl(void);   
        void HoldTopControl(void);
        int GetColor(void); //return type not determined (most likely 1 red, 2 green etc...)
        void SpinControl(void);
        void StopSpinControl(void);

};
