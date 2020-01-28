#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"

#define PID_SLOT 1

class Shooter : public frc::Subsystem {
    private:
        WPI_TalonFX m_leftShooterMotor{LEFT_SHOOTER_FALCON_ID};
        WPI_TalonFX m_rightShooterMotor{RIGHT_SHOOTER_FALCON_ID};
        WPI_TalonFX m_feederMotor{FEEDER_CAN_ID};
        WPI_VictorSPX m_carouselMotor{CAROUSEL_CAN_ID};
        
    public:
        Shooter();
        void InitDefaultCommand() override;
        void ShooterInit(void);
        void SetShooterSpeed(double velocityRPM);
        int GetShooterEncoder(void);
        double GetShooterVelocity(void);
        void SetFeederVelocity(double velocityRPM);
        bool GetShooterPhotoEye(void);
        void ExtendRamp(void);
        void RetractRamp(void);
        void StopFeeder(void);
        void StopShooter(void);
        void SetCarouselPower(void);
        void CarouselStop(void);

};
