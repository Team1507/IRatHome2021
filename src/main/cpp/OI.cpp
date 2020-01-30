#include "OI.h"
//#include <frc/WPILib.h>   //DO NOT INCLUDE THIS

#include <frc/smartdashboard/SmartDashboard.h>

#include "commands/CmdDriveClearAll.h"
#include "commands/GrpAutoDriveTest.h"


OI::OI() {
  // Process operator interface input here.

    //Init Gamepad
    m_drivergamepad = new frc::Joystick(0);
    m_operatorgamepad = new frc::Joystick(1);

    frc::SmartDashboard::PutData("CmdDriveClearAll",    new CmdDriveClearAll( ) );

    frc::SmartDashboard::PutData("GrpAutoDriveTest",    new GrpAutoDriveTest( ) );



}

frc::Joystick* OI::GetDriverGamepad() 
{
    return m_drivergamepad;
}
frc::Joystick* OI::GetOperatorGamepad() 
{
    return m_operatorgamepad;
}