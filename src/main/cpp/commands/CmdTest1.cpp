#include "commands/CmdTest1.h"
#include "subsystems/Shooter.h"
#include "Robot.h"
#include "subsystems/BallDeflector.h"
CmdTest1::CmdTest1() {}

void CmdTest1::Initialize()
{

    //SmartDashboard::PutNumber("Shooting Velocity", 0);
    double poop = SmartDashboard::GetNumber("Shooting Velocity", 0);
    Robot::m_shooter.SetShooterVelocity(poop);
    
    //Robot::m_shooter.ExtendRamp();
    //Robot::m_ballDeflector.DeployDeflector();
    
}

void CmdTest1::Execute() {}

bool CmdTest1::IsFinished() { return false; }

void CmdTest1::End() 
{
    //Robot::m_shooter.RetractRamp();
    //Robot::m_ballDeflector.RetractDeflector();
    Robot::m_shooter.SetShooterVelocity(0);
}

void CmdTest1::Interrupted() 
{
    End();
}
