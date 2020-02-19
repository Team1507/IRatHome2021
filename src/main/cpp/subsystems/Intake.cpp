#include "subsystems/Intake.h"
#include "Robot.h"
#define INTAKE_PERCENT .7 //can change


Intake::Intake() : Subsystem("ExampleSubsystem") 
{
    SmartDashboard::PutNumber("INTAKE_POWER", 0);
}


void Intake::InitDefaultCommand() {}


void Intake::IntakePeriodic()
{
    bool isTriggerPressed = (Robot::m_oi.GetOperatorGamepad()->GetRawAxis(GAMEPADMAP_AXIS_L_TRIG) >= .5);
    bool isBumperPressed  = (Robot::m_oi.GetOperatorGamepad()->GetRawButton(GAMEPADMAP_BUTTON_LBUMP) );
    
    if( isTriggerPressed && !m_isIntaking )
    {
        IntakeForward();
        m_isIntaking = true;
    }
    else if( isBumperPressed && !m_isIntaking )
    {
        IntakeBackward();
        m_isIntaking = true;
    }
    else if( m_isIntaking )
    {
        IntakeStop();
        m_isIntaking = false;
    }






}


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
    //temp code to read off the smart dashboard
    double percent = -(frc::SmartDashboard::GetNumber("INTAKE_POWER", 0));
    m_intakeMotor.Set(ControlMode::PercentOutput, percent);   
}


void Intake::IntakeForward(double power)
{
    m_intakeMotor.Set(ControlMode::PercentOutput, power);   
}