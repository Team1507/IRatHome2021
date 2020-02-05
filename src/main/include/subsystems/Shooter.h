#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"

#define CAROUSEL_SHOOTING_POWER   .7  //probably will change later REEEEEEE
#define CAROUSEL_IDLE_POWER       .5  //wIlL Be aDjUsTeD
#define FEEDER_SHOOTING_VELOCITY  600 //will change, like kids voices
#define SHOOTER_TRENCH_VELOCITY   500 //these will DEFINITELY CHANGE LATER ON, these values are temporary
#define SHOOTER_LINE_VELOCITY     400
#define SHOOTER_LOW_GOAL_VELOCITY 200
#define SHOOTER_IDLE_VELOCITY     100



class Shooter : public frc::Subsystem {
    private:
        WPI_TalonFX m_leftShooterMotor  {LEFT_SHOOTER_FALCON_ID};
        WPI_TalonFX m_rightShooterMotor {RIGHT_SHOOTER_FALCON_ID};
        WPI_TalonFX m_feederMotor       {FEEDER_CAN_ID};
        WPI_VictorSPX m_carouselMotor   {CAROUSEL_CAN_ID};

        bool m_isShooting;

        

        

    public:
        Shooter();
        void InitDefaultCommand() override;
        void ShooterPeriodic(void);
        void ShooterInit(void);
        void SetShooterVelocity(double velocityRPM);
        int GetShooterEncoder(void);
        double GetShooterVelocity(void);
        void SetFeederVelocity(double velocityRPM);
        bool GetShooterPhotoEye(void);
        void ExtendRamp(void);
        void RetractRamp(void);
        void StopFeeder(void);
        void StopShooter(void);
        void SetCarouselPower(double percent);
        void CarouselStop(void);
        
        // ******************************************************
        double m_carouselShootingPower;
        double m_carouselIdlePower;
        int    m_feederShootingVelocity;
        int    m_shooterTrenchVelocity;
        double m_shooterLineVelocity;
        int    m_shooterLowGoalVelocity;
        int    m_shooterIdleVelocity;
};
