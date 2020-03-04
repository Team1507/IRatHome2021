#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include <frc/Solenoid.h>
#include <frc/Servo.h>

#define CAROUSEL_SHOOTING_POWER   0.4  
#define CAROUSEL_IDLE_POWER       0.3  
#define FEEDER_SHOOTING_POWER     1.0 

//These are actuallty POWER for now...
#define SHOOTER_TRENCH_VELOCITY   1.0  
#define SHOOTER_LINE_VELOCITY     1.0
#define SHOOTER_LOW_GOAL_VELOCITY 0.4
#define SHOOTER_IDLE_VELOCITY     0.5
#define SHOOTER_ZERO_VELOCITY     0.0

#define LINE_HOOD_ANGLE           129  
#define TRENCH_HOOD_ANGLE         111 
#define LOWGOAL_HOOD_ANGLE        50  
#define HOME_HOOD_ANGLE           40
#define SHOOTER_WHEEL_DIAMETER    12.5663




class Shooter : public frc::Subsystem {
    private:
        WPI_TalonFX m_leftShooterMotor  {LEFT_SHOOTER_FALCON_ID};
        WPI_TalonFX m_rightShooterMotor {RIGHT_SHOOTER_FALCON_ID};
        WPI_TalonSRX m_feederMotor      {FEEDER_CAN_ID};
        WPI_VictorSPX m_carouselMotor   {CAROUSEL_CAN_ID};
        frc::Solenoid m_shooterramp     {PCM_CAN_ID,PCM_RAMP_ID};
     
        bool m_isShooting;
        
        frc::Servo m_shooterHood {SHOOTER_HOOD_PORT};

        int m_hood_angle;
        

    public:
        Shooter();
        void InitDefaultCommand() override;
        void ShooterInit(void);
        void ShooterPeriodic(void);
        void SetShooterVelocity(double velocityRPM);
        int GetShooterEncoder(void);
        double GetShooterVelocity(void);
        double GetShooterPower();
        void SetFeederVelocity(double velocityRPM);
        void SetFeederPower(double power);
        void ExtendRamp(void);
        void RetractRamp(void);
        void StopFeeder(void);
        void StopShooter(void);
        void SetCarouselPower(double percent);
        void SetCarouselIdlePower(void);
        void SetCarouselShootingPower(void);
        void CarouselStop(void);
        void SetHood(int angle);
        
        // ******************************************************
        double m_carouselShootingPower;
        double m_carouselIdlePower;
        int    m_feederShootingVelocity;
        int    m_shooterTrenchVelocity;
        double m_shooterLineVelocity;
        int    m_shooterLowGoalVelocity;
        int    m_shooterIdleVelocity;
};
