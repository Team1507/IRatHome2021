#include "commands/CmdReady2ShootTest.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "subsystems/Shooter.h"
CmdReady2ShootTest::CmdReady2ShootTest() {}

void CmdReady2ShootTest::Initialize() 
{
    Robot::m_shooter.m_carouselShootingPower = frc::SmartDashboard::GetNumber ("CAROUSEL_SHOOTING_POWER",0);
    Robot::m_shooter.m_carouselIdlePower = frc::SmartDashboard::GetNumber ("CAROUSEL_IDLE_POWER",0);
    Robot::m_shooter.m_feederShootingVelocity = frc::SmartDashboard::GetNumber ("FEEDER_SHOOTING_VELOCITY",0);
    Robot::m_shooter.m_shooterTrenchVelocity = frc::SmartDashboard::GetNumber ("SHOOTER_TRENCH_VELOCITY",0);
    Robot::m_shooter.m_shooterLineVelocity = frc::SmartDashboard::GetNumber ("SHOOTER_LINE_VELOCITY",0);
    Robot::m_shooter.m_shooterLowGoalVelocity = frc::SmartDashboard::GetNumber ("SHOOTER_LOW_GOAL_VELOCITY",0);
    Robot::m_shooter.m_shooterIdleVelocity = frc::SmartDashboard::GetNumber ("SHOOTER_IDLE_VELOCITY",0);

    Robot::m_shooter.SetShooterVelocity(Robot::m_shooter.m_shooterLineVelocity);
    Robot::m_shooter.SetCarouselPower(Robot::m_shooter.m_carouselIdlePower);


}

void CmdReady2ShootTest::Execute() {}

bool CmdReady2ShootTest::IsFinished() { return true; }

void CmdReady2ShootTest::End() {}

void CmdReady2ShootTest::Interrupted() {}
