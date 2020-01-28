#include "subsystems/Shooter.h"


Shooter::Shooter() : Subsystem("ShooterSubsystem") {}


void Shooter::InitDefaultCommand() {}


void Shooter::ShooterInit() {}


void Shooter::SetShooterSpeed(double velocityRPM){}


int Shooter::GetShooterEncoder(){}


double Shooter::GetShooterVelocity(){}


void Shooter::SetFeederVelocity(double velocityRPM){}