#include "subsystems/Shooter.h"


Shooter::Shooter() : Subsystem("ShooterSubsystem") {} 


void Shooter::InitDefaultCommand() {}


void Shooter::ShooterInit() {}


void Shooter::SetShooterSpeed(double velocityRPM){}


int Shooter::GetShooterEncoder(){}


double Shooter::GetShooterVelocity(){}


void Shooter::SetFeederVelocity(double velocityRPM){}


bool Shooter::GetShooterPhotoEye() {}


void Shooter::ExtendRamp(){}


void Shooter::RetractRamp(){}


void Shooter::StopFeeder(){}


void Shooter::StopShooter(){}


void Shooter::SetCarouselPower(){}


void Shooter::CarouselStop(){}