#include "commands/GrpAutoDriveTest.h"

#include "frc/commands/WaitCommand.h"

#include "commands/CmdDriveManual.h"
#include "commands/CmdDriveVelRampTest.h"
#include "commands/CmdPrintAutoText.h"
#include "commands/CmdDriveFwdEncoder.h"
#include "commands/CmdDriveFwdGyro.h"
#include "commands/CmdDriveFwdGyroV2.h"
#include "commands/CmdDriveRevEncoder.h"
#include "commands/CmdDriveRevGyro.h"
#include "commands/CmdDriveRevGyroV2.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveTurn2Angle.h"

GrpAutoDriveTest::GrpAutoDriveTest() 
{
	AddSequential(new CmdPrintAutoText("GrpAutoDriveTest Begin"));
    AddSequential(new CmdDriveClearAll());
    //***************************************************

    AddSequential(new CmdDriveFwdGyroV2(       0.4,            0.0,             120,        true, true,          0.0));

    AddSequential(new frc::WaitCommand(0.1));

    AddSequential(new CmdDriveRevGyroV2(       0.4,            0.0,             120,        true, true,          0.0));

    //***************************************************
    AddSequential(new CmdDriveManual(0,0,0) );          //Safety.  All Off
    AddSequential(new CmdPrintAutoText("GrpAutoDriveTest Complete"));
}
