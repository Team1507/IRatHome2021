#include "commands/CmdStopCarousel.h"
#include "subsystems/Shooter.h"
#include "Robot.h"

CmdStopCarousel::CmdStopCarousel() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

void CmdStopCarousel::Initialize() 
{
    Robot::m_shooter.CarouselStop();
}

void CmdStopCarousel::Execute() {}

bool CmdStopCarousel::IsFinished() { return true; }

void CmdStopCarousel::End() {}

void CmdStopCarousel::Interrupted() {}
