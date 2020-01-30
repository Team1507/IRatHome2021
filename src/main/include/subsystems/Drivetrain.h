#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "AHRS.h"

#include "frc/drive/DifferentialDrive.h"

#include "RobotMap.h"

class Drivetrain : public frc::Subsystem {
    private:
        WPI_TalonFX m_leftMotorFront  { LEFTDRIVE_FRONT_CAN_ID };
        WPI_TalonFX m_leftMotorBack   { LEFTDRIVE_BACK_CAN_ID  };
        WPI_TalonFX m_rightMotorFront { LEFTDRIVE_FRONT_CAN_ID };
        WPI_TalonFX m_rightMotorBack  { RIGHTDRIVE_BACK_CAN_ID };

        frc::DifferentialDrive m_differentialDrive{ m_leftMotorFront, m_rightMotorFront};

        AHRS m_ahrs{SPI::Port::kMXP};	    //NavX

    public:
        Drivetrain();
        void InitDefaultCommand() override;

        //Drivetrain Constants
        const static double LEFT_ENCODER_TPI;       //"Ticks per inch"
        const static double RIGHT_ENCODER_TPI;    

        void InitFalcons(void);
        void DriveWithGamepad(void);
        void Drive( double left, double right );
        void Stop(void);
        double GetRightMotor(void);
        double GetLeftMotor(void);

        //Encoders
        int GetLeftEncoder(void);
        int GetLeftEncoder2(void);
        int GetRightEncoder(void);
        int GetRightEncoder2(void);
        void ResetEncoders(void);

    //NavX
        bool   IsGyroConnected(void);
        double GetGyroYaw(void);            //yaw: Relative -180 to +180
        double GetGyroAngle(void);          //angle: absolute -inf to +inf
        double GetGyroRate(void);
        void   ZeroGyro(void);    

};
