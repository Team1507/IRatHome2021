#include "OI.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include "commands/AutoJustShoot.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/GrpAutoDriveTest.h"

#include "GamepadMap.h"
#include "commands/CmdTest1.h"
#include "commands/CmdTest2.h"
#include "commands/CmdSetCarouselPower.h"
#include "commands/CmdSetIntake.h"
#include "commands/CmdSetFeederVelocity.h"
#include "commands/CmdSpinnerDeploy.h"
OI::OI() {
  // Process operator interface input here.

    //Init Gamepad
    m_drivergamepad = new frc::Joystick(0);
    m_operatorgamepad = new frc::Joystick(1);

    frc::SmartDashboard::PutData("CmdDriveClearAll", new CmdDriveClearAll());
    frc::SmartDashboard::PutData("AutoShoot", new AutoJustShoot());
    frc::SmartDashboard::PutData("GrpAutoDriveTest", new GrpAutoDriveTest());

    frc::SmartDashboard::PutData("TEST 1", new CmdTest1());
    //frc::SmartDashboard::PutData("TEST 2", new CmdTest2());
    //frc::SmartDashboard::PutData("TEST 1", new CmdSetCarouselPower(0));
    frc::SmartDashboard::PutData("TEST 2", new CmdSetIntake(0));
    
    
    //frc::SmartDashboard::PutData("CmdSetShooterVelocity", new CmdSetFeederVelocity())
    //buttons
    m_spinnerDeployToggle = new frc::JoystickButton(m_operatorgamepad,GAMEPADMAP_BUTTON_A);
    m_spinnerDeployToggle->WhenPressed(new CmdSpinnerDeploy());




}

frc::Joystick* OI::GetDriverGamepad() 
{
    return m_drivergamepad;
}
frc::Joystick* OI::GetOperatorGamepad() 
{
    return m_operatorgamepad;
}