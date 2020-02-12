#include "commands/AutoDoNothing.h"

#include "commands/CmdPrintAutoText.h"
#include "commands/CmdDriveClearAll.h"

AutoDoNothing::AutoDoNothing() 
{
    AddSequential(new CmdPrintAutoText("******AUTO DO NOTHING******"));
    AddSequential(new CmdDriveClearAll());
}