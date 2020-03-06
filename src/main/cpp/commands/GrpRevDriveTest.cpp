#include "commands/GrpRevDriveTest.h"

#include "frc/commands/WaitCommand.h"

#include "commands/CmdDriveManual.h"
#include "commands/CmdDriveVelRampTest.h"
#include "commands/CmdPrintAutoText.h"
#include "commands/CmdDriveFwdEncoder.h"
#include "commands/CmdDriveFwdGyro.h"
#include "commands/CmdDriveRevEncoder.h"
#include "commands/CmdDriveRevGyro.h"
#include "commands/CmdDriveRevGyroV2.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveTurn2Angle.h"

GrpRevDriveTest::GrpRevDriveTest() 
{
	AddSequential(new CmdPrintAutoText("GrpRevDriveTest Begin"));
    AddSequential(new CmdDriveClearAll());
    //***************************************************

    //AddSequential(new CmdDriveRevGyro(       0.4,            0.0,             120,        true,          0.0));

    AddSequential(new CmdDriveRevGyroV2(       0.4,            0.0,             120,      true,  true,          0.0));


    //***************************************************
    AddSequential(new CmdDriveManual(0,0,0) );          //Safety.  All Off
    AddSequential(new CmdPrintAutoText("GrpRevDriveTest Complete"));
}
