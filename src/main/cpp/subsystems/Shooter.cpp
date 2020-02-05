#include "subsystems/Shooter.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"
#define SHOOTER_KF_CONSTANT .0575    //we'll need to fix this and adjust it later or else itll die
#define FEEDER_KF_CONSTANT  .68      //we'll need to adjust this later too
#define SHOOTER_PID_SLOT 0
#define FEEDER_PID_SLOT  1




Shooter::Shooter() : Subsystem("ShooterSubsystem") 
{
    m_isShooting = false;
} 



void Shooter::InitDefaultCommand() {}


void Shooter::ShooterPeriodic()
{
    //trench is up on DPad
    //down is shooting in the low goal
    //left is shooting from the initian line
    int povAngle = Robot::m_oi.GetOperatorGamepad()->GetPOV(0);//POV 0, only one POV on gamepad
    
    static bool isPovCenter = false;
    
    if(povAngle == -1)
    {
        isPovCenter = true;
        std::cout<<"nothing pressed"<<std::endl;
    }

    //this is to enable the shooting speed, after we have 5 balls
    if((povAngle == 0) && isPovCenter)
    {
        SetShooterVelocity(SHOOTER_TRENCH_VELOCITY);
        isPovCenter = false;
        std::cout<<"trench"<<std::endl;
    }
    else if((povAngle == 180)&& isPovCenter)
    {
        SetShooterVelocity(SHOOTER_LOW_GOAL_VELOCITY);
        isPovCenter = false;
        std::cout<<"low goal"<<std::endl;
    }
    else if((povAngle == 270) && isPovCenter)
    {
        SetShooterVelocity(SHOOTER_LINE_VELOCITY);
        isPovCenter = false;
        std::cout<<"line"<<std::endl;
    }
    
    //shooter button, right trigger, this is for after we aim
    bool m_isTriggerPressed = (Robot::m_oi.GetOperatorGamepad()->GetRawAxis(GAMEPADMAP_AXIS_R_TRIG) >= 0.5);
    if (m_isTriggerPressed)
    {
        //shooter should already be at shooting speed
        SetCarouselPower(CAROUSEL_SHOOTING_POWER);
        SetFeederVelocity(FEEDER_SHOOTING_VELOCITY);
        //intake ?
        //deflector deployed for some reason?
        //feeder

        m_isShooting = true;

    }
    else if(m_isShooting && !(m_isTriggerPressed))
    {
        //shooter at shooter speed still
        //stop carousel
        m_isShooting = false; 
    }

    //this will go from aiming to default driving, this is the 'reset' button
    //done shooting button, back to default
    if(Robot::m_oi.GetOperatorGamepad()->GetRawButtonPressed(GAMEPADMAP_BUTTON_RBUMP))
    {
        SetShooterVelocity(SHOOTER_IDLE_VELOCITY);
        SetCarouselPower(CAROUSEL_IDLE_POWER);
        SetFeederVelocity(0);
        //REENABLE ball intake
        m_isShooting = false;
        std::cout<<"Back to driving"<<std::endl;
    }

}


void Shooter::ShooterInit()
{
    //everything will be written to "m_leftShooterMotor" for the shooter
    m_leftShooterMotor.SetNeutralMode(NeutralMode::Brake);
    m_leftShooterMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
    //PID constants
    m_leftShooterMotor.Config_kF(SHOOTER_PID_SLOT, SHOOTER_KF_CONSTANT, 0);    
    m_feederMotor.Config_kF(FEEDER_PID_SLOT, FEEDER_KF_CONSTANT, 0);
    //right motor following
    m_rightShooterMotor.Follow(m_leftShooterMotor);
    m_rightShooterMotor.SetInverted(true);

    // *********************************************************
    // TEMP CODE
    frc::SmartDashboard::PutNumber("CAROUSEL_SHOOTING_POWER", 0.0);
    frc::SmartDashboard::PutNumber("CAROUSEL_IDLE_POWER", 0.0);
    frc::SmartDashboard::PutNumber("FEEDER_SHOOTING_VELOCITY", 0.0);
    frc::SmartDashboard::PutNumber("SHOOTER_TRENCH_VELOCITY", 0.0);
    frc::SmartDashboard::PutNumber("SHOOTER_LINE_VELOCITY", 0.0);
    frc::SmartDashboard::PutNumber("SHOOTER_LOW_GOAL_VELOCITY", 0.0);
    frc::SmartDashboard::PutNumber("SHOOTER_IDLE_VELOCITY", 0.0);


}


void Shooter::SetShooterVelocity(double velocityRPM)
{
    // rpm --> ticks per 100ms, 4096 ticks/revolution, 600 revs/ 100ms 
    m_leftShooterMotor.Set(ControlMode::Velocity, velocityRPM * 4096 / 600); //targetVelocity is in ticks/100ms
}


int Shooter::GetShooterEncoder()
{
    return m_leftShooterMotor.GetSensorCollection().GetIntegratedSensorPosition();
}


double Shooter::GetShooterVelocity()
{
    return m_leftShooterMotor.GetSelectedSensorVelocity(SHOOTER_PID_SLOT);
}


void Shooter::SetFeederVelocity(double velocityRPM)
{
    m_feederMotor.Set(ControlMode::Velocity ,velocityRPM * 4096 / 600);
}


bool Shooter::GetShooterPhotoEye() 
{
    return "poo" == "pee"; //Mr. Sielski said to make it return false so I did
}


void Shooter::ExtendRamp(){}


void Shooter::RetractRamp(){}


void Shooter::StopFeeder()
{
    m_feederMotor.Set(ControlMode::PercentOutput, 0);
}


void Shooter::StopShooter()
{
    m_leftShooterMotor.Set(ControlMode::PercentOutput, 0);
}


void Shooter::SetCarouselPower(double percent)
{
    m_carouselMotor.Set(ControlMode::PercentOutput, percent);
}


void Shooter::CarouselStop()
{
    m_carouselMotor.Set(ControlMode::PercentOutput, 0);   
}