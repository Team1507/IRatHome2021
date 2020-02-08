#include "subsystems/BallDeflector.h"

BallDeflector::BallDeflector() : Subsystem("ExampleSubsystem") {}

void BallDeflector::InitDefaultCommand()
{
   
}
 

void BallDeflector::DeployDeflector()
{
    m_linearActuator.SetAngle(45.0);
}


void BallDeflector::RetractDeflector()
{
     m_linearActuator.SetAngle(180.0);
}


