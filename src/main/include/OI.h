#pragma once

#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <frc/buttons/JoystickButton.h>

class OI {

    private:
        frc::Joystick *m_drivergamepad;
        frc::Joystick *m_operatorgamepad;
        //frc::JoystickButton *m_spinnerDeployToggle;
        frc::JoystickButton *m_driverAllowClimb;
        frc::JoystickButton *m_driverLimelightShoot;

    public:
        OI();
        frc::Joystick* GetDriverGamepad();
        frc::Joystick* GetOperatorGamepad();
};

