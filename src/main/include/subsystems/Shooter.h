#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"

#define PID_SLOT 1

class Shooter : public frc::Subsystem {
    private:
        WPI_TalonFX m_leftShooterMotor{LEFT_SHOOTER_FALCON_ADDRESS};
        WPI_TalonFX m_rightShooterMotor{RIGHT_SHOOTER_FALCON_ADDRESS};
        WPI_TalonFX m_feederMotor{FEEDER_CAN_ADDRESS};
    public:
        Shooter();
        void InitDefaultCommand() override;
        void ShooterInit(void);
        void SetShooterSpeed(double velocityRPM);
        int GetShooterEncoder(void);
        double GetShooterVelocity(void);
        void SetFeederVelocity(double velocityRPM);
};
