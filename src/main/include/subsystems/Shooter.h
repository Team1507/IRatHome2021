#pragma once

#include <frc/commands/Subsystem.h>

#include "ctre/Phoenix.h"
// #include "ctre/phoenix/motorcontrol/can/TalonSRX.h"
// #include "ctre/phoenix/motorcontrol/can/VictorSPX.h"
// #include "ctre/phoenix/motorcontrol/can/TalonFX.h"
// #include "ctre/phoenix/motorcontrol/ControlMode.h"
// #include "ctre/phoenix/motorcontrol/FeedbackDevice.h"
#include "RobotMap.h"
#include <frc/Solenoid.h>
#include <frc/Servo.h>

#define CAROUSEL_SHOOTING_POWER   0.4  
#define CAROUSEL_IDLE_POWER       0.3  
#define FEEDER_SHOOTING_POWER     1.0 

// //These are actuallty POWER for now...
// #define SHOOTER_TRENCH_VELOCITY   1.0  
// #define SHOOTER_LINE_VELOCITY     1.0
// #define SHOOTER_LOW_GOAL_VELOCITY 0.4
// #define SHOOTER_IDLE_VELOCITY     0.5
// #define SHOOTER_ZERO_VELOCITY     0.0

//These are velocities in Falcon (units/100ms)/1000  <<==notice divided by 1000
#define SHOOTER_TRENCH_VELOCITY   19  
#define SHOOTER_LINE_VELOCITY     18
#define SHOOTER_LOW_GOAL_VELOCITY 10
#define SHOOTER_IDLE_VELOCITY     10
#define SHOOTER_ZERO_VELOCITY     0

#define LINE_HOOD_ANGLE           129  
#define TRENCH_HOOD_ANGLE         111 
#define LOWGOAL_HOOD_ANGLE        50  
#define HOME_HOOD_ANGLE           40




class Shooter : public frc::Subsystem {
    private:
        TalonFX m_leftShooterMotor  {LEFT_SHOOTER_FALCON_ID};
        TalonFX m_rightShooterMotor {RIGHT_SHOOTER_FALCON_ID};
        TalonSRX m_feederMotor      {FEEDER_CAN_ID};

        VictorSPX m_carouselMotor   {CAROUSEL_CAN_ID};

        frc::Solenoid m_shooterramp     {PCM_CAN_ID,PCM_RAMP_ID};
     
        bool m_isShooting;
        
        frc::Servo m_shooterHood {SHOOTER_HOOD_PORT};

        int m_hood_angle;

        double m_shooterRPM;
        

    public:
        Shooter();
        void InitDefaultCommand() override;
        void ShooterInit(void);
        void ShooterPeriodic(void);
        void SetShooterVelocity(double velocityRPM);
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
