#include "commands/GrpFwdDriveTest.h"

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
#include "commands/CmdLoggingEnable.h"

GrpFwdDriveTest::GrpFwdDriveTest() 
{
	AddSequential(new CmdPrintAutoText("GrpFwdDriveTest Begin"));
    AddSequential(new CmdDriveClearAll());
    //***************************************************
    AddSequential(new CmdLoggingEnable(true));

    //AddSequential(new CmdDriveFwdGyro(       0.4,            0.0,             120,        true,          0.0));

    AddSequential(new CmdDriveFwdGyroV2(       0.4,            0.0,             120,   true,     true,          0.0));

    
    AddSequential(new frc::WaitCommand(1.0));           //Let it finish whatever it's doing
    AddSequential(new CmdLoggingEnable(false));
    //***************************************************
    AddSequential(new CmdDriveManual(0,0,0) );          //Safety.  All Off
    AddSequential(new CmdPrintAutoText("GrpFwdDriveTest Complete"));
}
