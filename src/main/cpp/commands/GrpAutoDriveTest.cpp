/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/GrpAutoDriveTest.h"

#include "frc/commands/WaitCommand.h"

#include "commands/CmdDriveManual.h"
#include "commands/CmdDriveVelRampTest.h"
#include "commands/CmdPrintAutoText.h"
#include "commands/CmdDriveFwdEncoder.h"
#include "commands/CmdDriveFwdGyro.h"
#include "commands/CmdDriveRevEncoder.h"
#include "commands/CmdDriveRevGyro.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveTurn2Angle.h"

GrpAutoDriveTest::GrpAutoDriveTest() 
{
	AddSequential(new CmdPrintAutoText("GrpAutoDriveTest Begin"));
    AddSequential(new CmdDriveClearAll());
    //***************************************************
    //AddSequential(new CmdLoggingEnable(true));

                    //CmdDriveRevGyro(double power, double heading, double distance, bool stop, double timeout)
    AddSequential(new CmdDriveRevGyro(       0.2,            0.0,             150,        true,          0.0));

    AddSequential(new frc::WaitCommand(1.0));

    AddSequential(new CmdDriveFwdGyro(       0.2,            0.0,             75,        true,          0.0));


    AddSequential(new CmdDriveTurn2Angle( 0.15, -15.0  ));


    //AddSequential( new CmdDriveManual( 0.2,  0.2, 3.0 ) );


    AddSequential(new frc::WaitCommand(1.0));           //Let it finish whatever it's doing
    //AddSequential(new CmdLoggingEnable(false));
    //***************************************************
    AddSequential(new CmdDriveManual(0,0,0) );          //Safety.  All Off
    AddSequential(new CmdPrintAutoText("GrpAutoDriveTest Complete"));
}
