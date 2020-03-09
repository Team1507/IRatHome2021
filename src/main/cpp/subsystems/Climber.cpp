#include "subsystems/Climber.h"
#include "Robot.h"
#define LIGHTSABER_UP_MULTIPLIER   .5
#define LIGHTSABER_DOWN_MULTIPLIER .25

#define WINCH_POWER 1.0
#define REVERSE_WINCH_POWER 0.4

Climber::Climber() : Subsystem("ExampleSubsystem") 
{
    m_isClimbActivated = false;
}

void Climber::InitDefaultCommand() {}

void Climber::ClimberPeriodic()
{
    double gamepadAxis = ((Robot::m_oi.GetOperatorGamepad()->GetRawAxis(GAMEPADMAP_AXIS_L_Y)) );
    double climberPower = 0;
    static bool isIdle = true;    //flag to prevent 0-spam

    //if pressed up, assign power upwards with up multiplier, if pressed downward use downward multiplier
    climberPower = (gamepadAxis < 0)? (gamepadAxis*LIGHTSABER_UP_MULTIPLIER) : (gamepadAxis*LIGHTSABER_DOWN_MULTIPLIER);
    
    if(Robot::m_oi.GetOperatorGamepad()->GetRawButton(GAMEPADMAP_BUTTON_Y)  && m_isClimbActivated )
    {
        MoveLightsaber(climberPower);
        isIdle = false;
    }
    else if(!isIdle)
    {
        isIdle = true;
        MoveLightsaber(0.0);
    }

    //**************
    //Climb Motor
    //bool driverClimb = Robot::m_oi.GetDriverGamepad()->GetRawButton(GAMEPADMAP_BUTTON_START);
    bool operatorClimb = Robot::m_oi.GetOperatorGamepad()->GetRawButton(GAMEPADMAP_BUTTON_START);
    bool reverseOperatorClimb = Robot::m_oi.GetOperatorGamepad()->GetRawButton(GAMEPADMAP_BUTTON_BACK);  

    if(operatorClimb && m_isClimbActivated) //&& driverClimb)
    {
        m_rightWinchMotor.Set(WINCH_POWER);
        m_leftWinchMotor.Set(WINCH_POWER);
    }
    else if( reverseOperatorClimb && m_isClimbActivated )
    {
        m_rightWinchMotor.Set(-REVERSE_WINCH_POWER);
        m_leftWinchMotor.Set(-REVERSE_WINCH_POWER);
    }
    else
    {
        m_rightWinchMotor.Set(0.0);
        m_leftWinchMotor.Set(0.0);
    }


    //SmartDashboard
    frc::SmartDashboard::PutBoolean("ClimbEnabled", m_isClimbActivated );    
}


void Climber::MoveLightsaber(double power)
{
    m_lightsaber.Set(power);
}


void Climber::SetClimbActivated()
{
    m_isClimbActivated = true;
}

void Climber::ClearClimbActivated()
{
    m_isClimbActivated = false;
}