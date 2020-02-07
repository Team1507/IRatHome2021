#include "subsystems/Intake.h"
#define INTAKE_PERCENT .7 //can change


Intake::Intake() : Subsystem("ExampleSubsystem") {}


void Intake::InitDefaultCommand() {}


void Intake::IntakeBackward()
{
    m_intakeMotor.Set(ControlMode::PercentOutput, -INTAKE_PERCENT);
}


void Intake::IntakeStop()
{
    m_intakeMotor.Set(ControlMode::PercentOutput, 0);  
}


void Intake::IntakeForward()
{
    m_intakeMotor.Set(ControlMode::PercentOutput, INTAKE_PERCENT);   
}
void Intake::IntakeForward(double power)
{
    m_intakeMotor.Set(ControlMode::PercentOutput, power);   
}