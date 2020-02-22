#include "subsystems/Shooter.h"
#include "Robot.h"
#include "frc/smartdashboard/SmartDashboard.h"

//#define SHOOTER_KF_CONSTANT .0575    //we'll need to fix this and adjust it later or else itll die
//#define FEEDER_KF_CONSTANT  .68      //we'll need to adjust this later too
#define SHOOTER_PID_SLOT 0
#define FEEDER_PID_SLOT  0      //BEN L thinks we don't need this anymore since we are just doin power on the shoooter?





Shooter::Shooter() : Subsystem("ShooterSubsystem") 
{
    m_isShooting = false;
    m_hood_angle = HOME_HOOD_ANGLE;
} 


void Shooter::InitDefaultCommand() {}


void Shooter::ShooterInit()
{
    m_leftShooterMotor.ConfigFactoryDefault();
    m_rightShooterMotor.ConfigFactoryDefault();
    m_feederMotor.ConfigFactoryDefault();
    
    //everything will be written to "m_leftShooterMotor" for the shooter
    m_leftShooterMotor.SetNeutralMode(NeutralMode::Coast);
    m_rightShooterMotor.SetNeutralMode(NeutralMode::Coast);
    m_feederMotor.SetNeutralMode(NeutralMode::Coast);

    //encoder
    m_leftShooterMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
    //m_feederMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);    //No Encoder
    
    //PID constants
    //m_leftShooterMotor.Config_kF(SHOOTER_PID_SLOT, SHOOTER_KF_CONSTANT, 0);    
    //m_feederMotor.Config_kF(FEEDER_PID_SLOT, FEEDER_KF_CONSTANT, 0);
    
    //right motor following and set inverted
    m_leftShooterMotor.SetInverted(true);
    m_rightShooterMotor.SetInverted(false);
    m_feederMotor.SetInverted(true);

    //set follow
    m_rightShooterMotor.Follow(m_leftShooterMotor);

    //*********************************************************
    //Shooter Setup TEMP CODE
    frc::SmartDashboard::PutNumber("CAROUSEL_IDLE_POWER",       CAROUSEL_IDLE_POWER    );
    frc::SmartDashboard::PutNumber("CAROUSEL_SHOOTING_POWER",   CAROUSEL_SHOOTING_POWER);
    frc::SmartDashboard::PutNumber("FEEDER_POWER",              FEEDER_SHOOTING_POWER  );

    frc::SmartDashboard::PutNumber("SHOOTER_IDLE_VELOCITY",     SHOOTER_IDLE_VELOCITY    );
    frc::SmartDashboard::PutNumber("SHOOTER_TRENCH_VELOCITY",   SHOOTER_TRENCH_VELOCITY  );
    frc::SmartDashboard::PutNumber("SHOOTER_LOW_GOAL_VELOCITY", SHOOTER_LOW_GOAL_VELOCITY);
    frc::SmartDashboard::PutNumber("SHOOTER_LINE_VELOCITY",     SHOOTER_LINE_VELOCITY    );

    //frc::SmartDashboard::PutNumber("SHOOTER Kf", 0);
    //frc::SmartDashboard::PutNumber("SHOOTER Kp", 0);

    SmartDashboard::PutNumber("INTAKE_POWER", 0.7);

}


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
        //std::cout<<"nothing pressed"<<std::endl;
    }

    //this is to enable the shooting speed, after we have 5 balls
    if((povAngle == 0) && isPovCenter)
    {
        //SetShooterVelocity(SHOOTER_TRENCH_VELOCITY);
        double shootpower = SmartDashboard::GetNumber("SHOOTER_TRENCH_VELOCITY", 0); 
        SetShooterVelocity(shootpower);

        isPovCenter = false;
        std::cout<<"Shoot Trench "<<std::endl;
        SetHood(0);//THE ZERO WILL CHANGE
        m_hood_angle = TRENCH_HOOD_ANGLE;
    }
    else if((povAngle == 180)&& isPovCenter)
    {
        //SetShooterVelocity(SHOOTER_LOW_GOAL_VELOCITY);
        double shootpower = SmartDashboard::GetNumber("SHOOTER_LOW_GOAL_VELOCITY", 0); 
        SetShooterVelocity(shootpower);
        isPovCenter = false;
        std::cout<<"Shoot low goal"<<std::endl;
        SetHood(0);//THE ZERO WILL CHANGE
        m_hood_angle = LOWGOAL_HOOD_ANGLE;
    }
    else if((povAngle == 270) && isPovCenter)
    {
        //SetShooterVelocity(SHOOTER_LINE_VELOCITY);
        double shootpower = SmartDashboard::GetNumber("SHOOTER_LINE_VELOCITY", 0); 
        SetShooterVelocity(shootpower);
        isPovCenter = false;
        std::cout<<"Shoot line"<<std::endl;
        SetHood(0);//THE ZERO WILL CHANGE
        m_hood_angle = LINE_HOOD_ANGLE;
    }
    
    //shooter button, right trigger, this is for after we aim
    bool m_isTriggerPressed = (Robot::m_oi.GetOperatorGamepad()->GetRawAxis(GAMEPADMAP_AXIS_R_TRIG) >= 0.5);
    if (m_isTriggerPressed && !m_isShooting)
    {
        //shooter should already be at shooting speed
        SetCarouselShootingPower();
        SetFeederPower(FEEDER_SHOOTING_POWER);
        ExtendRamp();
        std::cout<<"Shoot!"<<std::endl;
        //intake ?
        //deflector deployed for some reason?
        //feeder
        m_isShooting = true;
    }
    else if(m_isShooting && !m_isTriggerPressed)
    {
        //shooter at shooting speed still
        SetCarouselIdlePower();
        RetractRamp();
        StopFeeder();
        m_isShooting = false; 
    }

    //*******   RESET  ******
    if(Robot::m_oi.GetOperatorGamepad()->GetRawButtonPressed(GAMEPADMAP_BUTTON_RBUMP))
    {
        //SetShooterVelocity(SHOOTER_IDLE_VELOCITY);
        double shootpower = SmartDashboard::GetNumber("SHOOTER_IDLE_VELOCITY", 0); 
        SetShooterVelocity(shootpower);
        SetCarouselIdlePower();
        StopFeeder();
        RetractRamp();
        SetHood(HOME_HOOD_ANGLE);
        m_hood_angle = HOME_HOOD_ANGLE;
        m_isShooting = false;
        std::cout<<"Shoot Reset"<<std::endl;
    }


    ////*****  SET HOOD AFTER DPAD (after crossing under wheel-of-fortune)
    if(Robot::m_oi.GetOperatorGamepad()->GetRawButtonPressed(GAMEPADMAP_BUTTON_X))
    {
        SetHood(m_hood_angle);
        std::cout<<"SetHood"<<std::endl;
    }


    //*******   REVERSE to Clear any jams
    bool isBumperPressed  = Robot::m_oi.GetOperatorGamepad()->GetRawButtonPressed(GAMEPADMAP_BUTTON_LBUMP);
    bool isBumperReleased = Robot::m_oi.GetOperatorGamepad()->GetRawButtonReleased(GAMEPADMAP_BUTTON_LBUMP);
    
    if(isBumperPressed)
    {
        SetCarouselPower(-CAROUSEL_IDLE_POWER);
    }
    else if (isBumperReleased)
    {
        SetCarouselPower(CAROUSEL_IDLE_POWER);
    }



}


void Shooter::SetShooterVelocity(double velocityRPM)
{

    //**** NOTE ***  THIS IS SHOOTER POWER FOR NOW, not velocity
    m_leftShooterMotor.Set(ControlMode::PercentOutput, velocityRPM );


//    // rpm --> ticks per 100ms, 4096 ticks/revolution, 600 revs/ 100ms
//    double tempV = SmartDashboard::GetNumber("SHOOTER_VELOCITY", 0); 
//    //m_leftShooterMotor.Set(ControlMode::Velocity, velocityRPM * 4096 / 600);
//    //m_leftShooterMotor.Set(ControlMode::Velocity, tempV * 4096 / 600); //targetVelocity is in ticks/100ms
//    m_leftShooterMotor.Set(ControlMode::PercentOutput, tempV ); //For Testing Only!
}


int Shooter::GetShooterEncoder()
{
    return m_leftShooterMotor.GetSensorCollection().GetIntegratedSensorPosition();
}


double Shooter::GetShooterVelocity()
{
    return m_leftShooterMotor.GetSelectedSensorVelocity(SHOOTER_PID_SLOT);
}

double Shooter::GetShooterPower()
{
    return m_leftShooterMotor.GetMotorOutputPercent();
}

void Shooter::SetFeederVelocity(double velocityRPM)
{
    //No Encoder, Use SetFeederPower instead.
    // double tempV = SmartDashboard::GetNumber("FEEDER_VELOCITY", 0);
    // //m_feederMotor.Set(ControlMode::Velocity ,tempV * 4096 / 600);
    // //m_feederMotor.Set(ControlMode::Velocity ,velocityRPM * 4096 / 600);
    // m_feederMotor.Set(ControlMode::PercentOutput ,tempV);
}
void Shooter::SetFeederPower(double power)
{
    double tempP = SmartDashboard::GetNumber("FEEDER_POWER", 0);
    m_feederMotor.Set(ControlMode::PercentOutput ,tempP);
}

void Shooter::ExtendRamp()
{
    m_shooterramp.Set(true);
}


void Shooter::RetractRamp()
{
    m_shooterramp.Set(false);
}


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
    // double tempP = SmartDashboard::GetNumber("CAROUSEL_POWER", 0);
    // m_carouselMotor.Set(ControlMode::PercentOutput, tempP);
    m_carouselMotor.Set(ControlMode::PercentOutput, percent);
}


void Shooter::SetCarouselIdlePower(void)
{
    double tempVar = frc::SmartDashboard::GetNumber("CAROUSEL_IDLE_POWER", 0.0);
    SetCarouselPower(tempVar);
}


void Shooter::SetCarouselShootingPower(void)
{
    double tempVar = frc::SmartDashboard::GetNumber("CAROUSEL_SHOOTING_POWER", 0.0);
    SetCarouselPower(tempVar);
}


void Shooter::CarouselStop()
{
    m_carouselMotor.Set(ControlMode::PercentOutput, 0);   
}


void Shooter::SetHood(int angle)
{
    //max 142, min 40
    m_shooterHood.SetAngle(angle);
    std::cout<<"HOOD ANGLE: "<<angle<<std::endl;
}