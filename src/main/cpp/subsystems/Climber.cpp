#include "subsystems/Climber.h"
#include "Robot.h"
#define LIGHTSABER_UP_MULTIPLIER   .6
#define LIGHTSABER_DOWN_MULTIPLIER .3

#define WINCH_SPEED .4

Climber::Climber() : Subsystem("ExampleSubsystem") {}


void Climber::ClimberPeriodic()
{
    double gamepadAxis = ((Robot::m_oi.GetOperatorGamepad()->GetRawAxis(GAMEPADMAP_AXIS_L_Y))*-1);
    double climberPower = 0;
    bool isIdle = 0;    //flag to prevent 0-spam

    //if pressed up, assign power upwards with up multiplier, if pressed downward use downward multiplier
    climberPower = (gamepadAxis > 0)? (gamepadAxis*LIGHTSABER_UP_MULTIPLIER):(gamepadAxis*LIGHTSABER_DOWN_MULTIPLIER);

    if(Robot::m_oi.GetOperatorGamepad()->GetRawButton(GAMEPADMAP_BUTTON_Y))
    {
        MoveLightsaber(climberPower);
        isIdle = false;
    }
    else if(!isIdle)
    {
        isIdle = true;
        MoveLightsaber(0.0);
    }
}


void Climber::InitDefaultCommand() {}


void Climber::MoveLightsaber(double power)
{
    m_lightsaber.Set(power);
}


void Climber::RetractWinch()
{
    m_rightWinchMotor.Set(WINCH_SPEED);
    m_leftWinchMotor.Set(WINCH_SPEED);
}

