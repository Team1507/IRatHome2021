/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/GrpSlalomPath.h"

#include "frc/commands/WaitCommand.h"

#include "commands/CmdDriveManual.h"
#include "commands/CmdDriveVelRampTest.h"
#include "commands/CmdPrintAutoText.h"
#include "commands/CmdDriveFwdEncoder.h"
#include "commands/CmdDriveFwdGyro.h"
#include "commands/CmdDriveFwdGyroV2.h"
#include "commands/CmdDriveRevEncoder.h"
#include "commands/CmdDriveRevGyro.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveTurn2Angle.h"

GrpSlalomPath::GrpSlalomPath() 
{

	  AddSequential(new CmdPrintAutoText("GrpSlalomPath Begin"));
    AddSequential(new CmdDriveClearAll());
    //***************************************************


    AddSequential(new CmdDriveFwdGyroV2(       0.3,            0.0,             6,    true,     false,          0.0));
    AddSequential(new CmdDriveFwdGyroV2(       0.3,            -90.0,           84,   false,     false,          0.0));

    AddSequential(new CmdDriveFwdGyroV2(       0.4,            45,             24,   false,     false,          0.0));
    AddSequential(new CmdDriveFwdGyroV2(       0.4,            0.0,            132,   false,     false,          0.0));


    AddSequential(new CmdDriveFwdGyroV2(       0.4,            100,            48,   false,     false,          0.0));

    AddSequential(new CmdDriveFwdGyroV2(       0.4,            60 ,            80,   false,     false,          0.0));


  //***********************
  //The big turn
    AddSequential(new CmdDriveFwdGyroV2(       0.2,              0 ,            66,   false,     false,          0.0));
    AddSequential(new CmdDriveFwdGyroV2(       0.2,            -90 ,          76,   false,     false,          0.0));
    AddSequential(new CmdDriveFwdGyroV2(       0.2,            -180 ,         76,   false,     false,          0.0));
    AddSequential(new CmdDriveFwdGyroV2(       0.2,            -270 ,         66,   false,     false,          0.0));
    //AddSequential(new CmdDriveFwdGyroV2(       0.2,            -330 ,         66,   false,     false,          0.0));

    AddSequential(new CmdDriveFwdGyroV2(       0.3,            -250 ,         24,   false,     false,          0.0));

    //Straightaway
    AddSequential(new CmdDriveFwdGyroV2(       0.4,            -90 ,         24,   false,     false,          0.0));
    AddSequential(new CmdDriveFwdGyroV2(       0.4,            -180 ,       150,   false,     false,          0.0));

    //Turn back into finish zone
    AddSequential(new CmdDriveFwdGyroV2(       0.4,            -100 ,       24,   false,     false,          0.0));
    AddSequential(new CmdDriveFwdGyroV2(       0.4,            -135 ,       100,   false,     false,          0.0));

    //***************************************************
    AddSequential(new CmdDriveManual(0,0,0) );          //Safety.  All Off
    AddSequential(new CmdPrintAutoText("GrpSlalomPath Complete"));

}
