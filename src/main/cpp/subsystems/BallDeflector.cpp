#include "subsystems/BallDeflector.h"


#define EXTEND_VAL 420
#define RETRACT_VAL 69


BallDeflector::BallDeflector() : Subsystem("ExampleSubsystem") {}


void BallDeflector::InitDefaultCommand(){}
 

void BallDeflector::DeployDeflector()
{
    m_linearActuator.SetAngle(EXTEND_VAL);
}


void BallDeflector::RetractDeflector()
{
    m_linearActuator.SetAngle(RETRACT_VAL);
}