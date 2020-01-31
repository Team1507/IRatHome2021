#include "commands/CmdSetIntake.h"
#include "Robot.h"


CmdSetIntake::CmdSetIntake(bool isRunning) {
    m_isRunning = isRunning;
}
void CmdSetIntake::Initialize() 
{
    if(m_isRunning)
    {
        Robot::m_intake.IntakeForward();
    }
    else if(!m_isRunning)
    {
        Robot::m_intake.IntakeStop();
    }
}

void CmdSetIntake::Execute() {}

bool CmdSetIntake::IsFinished() { return true; }

void CmdSetIntake::End() {}

void CmdSetIntake::Interrupted() {}
