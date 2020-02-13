#pragma once

#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <frc/buttons/JoystickButton.h>

class OI {

    private:
        frc::Joystick *m_drivergamepad;
        frc::Joystick *m_operatorgamepad;
        frc::JoystickButton *m_spinnerDeployToggle;
    public:
        OI();
        frc::Joystick* GetDriverGamepad();
        frc::Joystick* GetOperatorGamepad();
};

