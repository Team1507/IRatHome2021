/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "OI.h"
//#include <frc/WPILib.h>   //DO NOT INCLUDE THIS

#include <frc/smartdashboard/SmartDashboard.h>

#include "commands/CmdDriveClearAll.h"
#include "commands/GrpAutoDriveTest.h"


OI::OI() {
  // Process operator interface input here.

    //Init Gamepad
    m_drivergamepad = new frc::Joystick(0);

    frc::SmartDashboard::PutData("CmdDriveClearAll",    new CmdDriveClearAll( ) );

    frc::SmartDashboard::PutData("GrpAutoDriveTest",    new GrpAutoDriveTest( ) );



}

frc::Joystick* OI::GetDriverGamepad() 
{
    return m_drivergamepad;
}
