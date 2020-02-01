#include "commands/CmdStopFeeder.h"
#include "subsystems/Shooter.h"
#include "Robot.h"


CmdStopFeeder::CmdStopFeeder() {}

void CmdStopFeeder::Initialize() 
{
    Robot::m_shooter.StopFeeder();
}

void CmdStopFeeder::Execute() {}

bool CmdStopFeeder::IsFinished() { return true; }


void CmdStopFeeder::End() {}


void CmdStopFeeder::Interrupted() {}
