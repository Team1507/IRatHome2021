/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/GrpSlalomPathAuto.h"
#include "frc/commands/WaitCommand.h"
#include "commands/CmdPrintAutoText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdRunPurePursuit.h"
#include "commands/CmdDriveManual.h"

GrpSlalomPathAuto::GrpSlalomPathAuto() 
{

	  AddSequential(new CmdPrintAutoText("GrpSlalomPathAuto Begin"));
    AddSequential(new CmdDriveClearAll());
    //***************************************************

    AddSequential( new CmdRunPurePursuit( "output") );
    AddSequential( new CmdRunPurePursuit( "output2") );

    //***************************************************
    AddSequential(new CmdDriveManual(0,0,0) );          //Safety.  All Off
    AddSequential(new CmdPrintAutoText("GrpSlalomPathAuto Complete"));

}
