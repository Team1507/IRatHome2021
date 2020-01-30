#pragma once

#include <frc/Joystick.h>
#include <frc/XboxController.h>

class OI {

    private:
        frc::Joystick *m_drivergamepad;
        frc::Joystick *m_operatorgamepad;
    public:
        OI();
        frc::Joystick* GetDriverGamepad();
        frc::Joystick* GetOperatorGamepad();
};

