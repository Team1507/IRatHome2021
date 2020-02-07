#include "commands/CmdSetIntake.h"
#include "Robot.h"
#include "subsystems/Intake.h"

CmdSetIntake::CmdSetIntake(bool isRunning) 
{
    m_isRunning = isRunning;
}
void CmdSetIntake::Initialize() 
{
    frc::SmartDashboard::PutNumber("Intake Power", 0);
    // if(m_isRunning)
    // {
    //     Robot::m_intake.IntakeForward();
    // }
    // else if(!m_isRunning)
    // {
    //     Robot::m_intake.IntakeStop();
    // }

}

void CmdSetIntake::Execute() 
{
    double power = frc::SmartDashboard::GetNumber("Intake Power", 0);
    Robot::m_intake.IntakeForward( power );
 
}

bool CmdSetIntake::IsFinished() { return false; }

void CmdSetIntake::End() {}

void CmdSetIntake::Interrupted() {}
