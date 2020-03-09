#include "commands/CmdTurnToLimelight.h"
#include "Robot.h"
#include "AHRS.h"
#include <math.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#define TOLRENCEZONE 0.5               //was 0.17

CmdTurnToLimelight::CmdTurnToLimelight() 
{
    m_Kp = 0.0015;
    m_minPower = 0.125;

    // Use Requires() here to declare subsystem dependencies
    Requires(&Robot::m_drivetrain);
}


void CmdTurnToLimelight::Initialize() 
{

    std::cout<< "CmdTurnToLimelight Init" << std::endl;

    double camera_offset = frc::SmartDashboard::GetNumber( "LimelightOffset", 0.0 );

    bool isTarget = nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tv", 0);

    if( isTarget )
    {
        m_targetAngle = Robot::m_drivetrain.GetGyroYaw() + nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tx", 0);
        m_targetAngle += camera_offset;
    }
    else
    {
        std::cout<< "   *** No Target" << std::endl;
        m_targetAngle = Robot::m_drivetrain.GetGyroYaw();   //Target is at whatever angle we are at
    }
    


    // frc::SmartDashboard::PutNumber( "Angle From Camera", 0.0 );
    // nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tx", 0) = frc::SmartDashboard::GetNumber( "Angle From Camera", 0.0 );

    std::cout<<"   CURR ANGLE "   << Robot::m_drivetrain.GetGyroYaw();
    std::cout<<"   TARGET ANGLE " << m_targetAngle<<std::endl;

    SetTimeout ( 3.0 );
}

void CmdTurnToLimelight::Execute() 
{
    double error = m_targetAngle - Robot::m_drivetrain.GetGyroYaw();
    double leftDrive = 0;
    double rightDrive = 0;
    //frc::SmartDashboard::PutNumber("ERROR CMDTURN2LIMELIGHT", error);
    if(error > TOLRENCEZONE)
    {
        // right turn
        leftDrive  = -((m_Kp * error) + m_minPower);
        rightDrive =  ((m_Kp * error) + m_minPower);
    }
    else if(error < -TOLRENCEZONE)
    {
        // left turn
        leftDrive  = -((m_Kp * error) - m_minPower);
        rightDrive =  ((m_Kp * error) - m_minPower);
    }
    else
    {
        //Right on target 
        leftDrive  = 0;
        rightDrive = 0;
    }
    Robot::m_drivetrain.Drive( -leftDrive, -rightDrive );
}


bool CmdTurnToLimelight::IsFinished()
 { 
    float curr_yaw = Robot::m_drivetrain.GetGyroYaw();
     
    if(((m_targetAngle - TOLRENCEZONE) <= curr_yaw) && ((m_targetAngle + TOLRENCEZONE) >= curr_yaw)) 
    {
        std::cout<<"Finished, CMDTURN2LIMELIGHT: "<<m_targetAngle - curr_yaw<<std::endl;
        return true;
    }

    if( IsTimedOut() )
    {
        std::cout<< "CmdTurnToLimelight TIMEOUT!!!!" << std::endl;
        return true;
    }

    return false; 
 }

void CmdTurnToLimelight::End() 
{
    Robot::m_drivetrain.Drive(0,0);
    std::cout<< "CmdTurnToLimelight Ended!" << std::endl;

}

void CmdTurnToLimelight::Interrupted() 
{
    End();
}