#include "commands/AutoDriveStr8.h"
#include "commands/CmdDriveFwdGyro.h"

#include "commands/CmdPrintAutoText.h"
#include "commands/CmdDriveClearAll.h"

AutoDriveStr8::AutoDriveStr8() 
{
  AddSequential(new CmdPrintAutoText("******AUTO DRIVE STR8******"));
  AddSequential(new CmdDriveClearAll());
  AddSequential(new CmdDriveFwdGyro(0.2, 0.0, 75, true, 0.0));
}
