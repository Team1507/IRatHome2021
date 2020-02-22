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
        WPI_TalonFX m_rightMotorFront { RIGHTDRIVE_FRONT_CAN_ID };
        WPI_TalonFX m_rightMotorBack  { RIGHTDRIVE_BACK_CAN_ID };

        frc::DifferentialDrive m_differentialDrive{ m_leftMotorFront, m_rightMotorFront};

        AHRS m_ahrs{SPI::Port::kMXP};	    //NavX


        //Local Encoders
        int m_l1_enc_zero;
        int m_l2_enc_zero;
        int m_r1_enc_zero;
        int m_r2_enc_zero;

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
        void HardResetEncoders(void);   //Full Falcon Encoder Reset
        void ResetEncoders(void);       //Local Reset

    //NavX
        bool   IsGyroConnected(void);
        double GetGyroYaw(void);            //yaw: Relative -180 to +180
        double GetGyroAngle(void);          //angle: absolute -inf to +inf
        double GetGyroRate(void);
        void   ZeroGyro(void);    

};
