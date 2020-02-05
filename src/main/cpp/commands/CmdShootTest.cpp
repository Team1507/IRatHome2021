#include "commands/CmdShootTest.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"

CmdShootTest::CmdShootTest() {}

void CmdShootTest::Initialize() 
{  
    Robot::m_shooter.m_carouselShootingPower = frc::SmartDashboard::GetNumber ("CAROUSEL_SHOOTING_POWER",0);
    Robot::m_shooter.m_carouselIdlePower = frc::SmartDashboard::GetNumber ("CAROUSEL_IDLE_POWER",0);
    Robot::m_shooter.m_feederShootingVelocity = frc::SmartDashboard::GetNumber ("FEEDER_SHOOTING_VELOCITY",0);
    Robot::m_shooter.m_shooterTrenchVelocity = frc::SmartDashboard::GetNumber ("SHOOTER_TRENCH_VELOCITY",0);
    Robot::m_shooter.m_shooterLineVelocity = frc::SmartDashboard::GetNumber ("SHOOTER_LINE_VELOCITY",0);
    Robot::m_shooter.m_shooterLowGoalVelocity = frc::SmartDashboard::GetNumber ("SHOOTER_LOW_GOAL_VELOCITY",0);
    Robot::m_shooter.m_shooterIdleVelocity = frc::SmartDashboard::GetNumber ("SHOOTER_IDLE_VELOCITY",0);  


    //***************************************************************


    Robot::m_shooter.SetShooterVelocity(Robot::m_shooter.m_shooterLineVelocity);
    Robot::m_shooter.SetCarouselPower(Robot::m_shooter.m_carouselShootingPower);
    Robot::m_shooter.SetFeederVelocity(Robot::m_shooter.m_feederShootingVelocity);
    Robot::m_shooter.ExtendRamp();






}

void CmdShootTest::Execute() {}

bool CmdShootTest::IsFinished() { return true; }

void CmdShootTest::End() {}

void CmdShootTest::Interrupted() {}
