#include "OI.h"

#include <frc/smartdashboard/SmartDashboard.h>
//#include "commands/AutoJustShoot.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/GrpAutoDriveTest.h"
#include "commands/GrpFwdDriveTest.h"
#include "commands/GrpRevDriveTest.h"
#include "commands/GrpVelocityRampTest.h"

#include "GamepadMap.h"
// #include "commands/CmdTest1.h"
// #include "commands/CmdTest2.h"
// #include "commands/CmdSetCarouselPower.h"
// #include "commands/CmdSetIntake.h"
// #include "commands/CmdSetFeederVelocity.h"
// #include "commands/CmdSpinnerDeploy.h"
// #include "commands/CmdTurnToLimelight.h"
// #include "commands/CmdStopCarousel.h"
// #include "commands/CmdEnableClimb.h"
#include "commands/GrpSlalomPath.h"
#include "commands/CmdRunPurePursuit.h"
#include "commands/GrpSlalomPathAuto.h"

OI::OI() {
  // Process operator interface input here.

    //Init Gamepad
    m_drivergamepad = new frc::Joystick(0);
    m_operatorgamepad = new frc::Joystick(1);

    frc::SmartDashboard::PutData("CmdDriveClearAll", new CmdDriveClearAll());
    //frc::SmartDashboard::PutData("AutoShoot", new AutoJustShoot());
    
    frc::SmartDashboard::PutData("GrpAutoDriveTest", new GrpAutoDriveTest());
    frc::SmartDashboard::PutData("GrpFwdDriveTest", new GrpFwdDriveTest());
    frc::SmartDashboard::PutData("GrpRevDriveTest", new GrpRevDriveTest());

    frc::SmartDashboard::PutData("GrpSlalomPath", new GrpSlalomPath());

    frc::SmartDashboard::PutData("CmdRunPurePursuit",   new CmdRunPurePursuit( "output") );

    frc::SmartDashboard::PutData("GrpSlalomPathAuto",   new GrpSlalomPathAuto() );

    frc::SmartDashboard::PutData("GrpVelocityRampTest",   new GrpVelocityRampTest() );


    // //frc::SmartDashboard::PutData("TEST 1", new CmdTest1());
    // //frc::SmartDashboard::PutData("TEST 2", new CmdSetIntake(0));
    // frc::SmartDashboard::PutData("CmdTurnToLimelight", new CmdTurnToLimelight());
    // frc::SmartDashboard::PutData("kill carousel", new CmdStopCarousel());
    // frc::SmartDashboard::PutData("Enable Climb", new CmdEnableClimb());
    
    
    
    // // //buttons1
    // //m_spinnerDeployToggle = new frc::JoystickButton(m_operatorgamepad,GAMEPADMAP_BUTTON_A);
    // //m_spinnerDeployToggle->WhenPressed(new CmdSpinnerDeploy());

    // m_driverLimelightShoot = new frc::JoystickButton(m_drivergamepad,GAMEPADMAP_BUTTON_RBUMP);
    // m_driverLimelightShoot->WhenPressed(new CmdTurnToLimelight());

    // m_driverAllowClimb = new frc::JoystickButton(m_drivergamepad, GAMEPADMAP_BUTTON_START);
    // m_driverAllowClimb->WhenPressed(new CmdEnableClimb());

}

frc::Joystick* OI::GetDriverGamepad() 
{
    return m_drivergamepad;
}
frc::Joystick* OI::GetOperatorGamepad() 
{
    return m_operatorgamepad;
}