#include "Robot.h"
#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "subsystems/Shooter.h"
#include "subsystems/Intake.h"
#include "subsystems/DriverFeedback.h"


Drivetrain Robot::m_drivetrain;
Odometry   Robot::m_odometry;
frc::Timer Robot::m_timer;

Shooter Robot::m_shooter;
Intake Robot::m_intake;

DriverFeedback Robot::m_driverFeedback;

//Must be last
OI Robot::m_oi;


//local function prototypes
void Write2Dashboard(void);


void Robot::RobotInit() {

    //*************************** INIT ******************************
    std::cout<<"RobotInit"<<std::endl;
    std::cout<<"FRC2020: Infinite Recharge ~~~DotMatrix~~~"<<std::endl;
    std::cout<<"Version: " << __DATE__ <<"  "<<__TIME__<<std::endl<<std::endl; 
    //****** Subsystems Init ******
    m_drivetrain.InitFalcons();
    m_odometry.Reset();
    m_shooter.ShooterInit();
    // //Auto Chooser
    // m_chooser.SetDefaultOption("Default Auto", &m_defaultAuto);
    // m_chooser.AddOption("My Auto", &m_myAuto);
    // frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

}


void Robot::RobotPeriodic() 
{
    m_odometry.OdometryPeriodic();
    Write2Dashboard();
}


void Robot::DisabledInit() 
{
    std::cout<<"Disabled Init"<<std::endl;
}


void Robot::DisabledPeriodic() 
{   
    frc::Scheduler::GetInstance()->Run(); 
}


void Robot::AutonomousInit() 
{

    std::cout<<"Auto Init"<<std::endl;
    std::cout<<"****NOTHING TO DO!!!*****"<<std::endl;

    // m_autonomousCommand = m_chooser.GetSelected();
    // if (m_autonomousCommand != nullptr) { m_autonomousCommand->Start();   }
}


void Robot::AutonomousPeriodic() { frc::Scheduler::GetInstance()->Run(); }


void Robot::TeleopInit() 
{
    std::cout<<"Teleop Init"<<std::endl;


    //Make sure Auto is not running in Teleop
    if (m_autonomousCommand != nullptr) 
    {
        m_autonomousCommand->Cancel();
        m_autonomousCommand = nullptr;
    }
}


void Robot::TeleopPeriodic() 
{ 

    m_shooter.ShooterPeriodic();

    frc::Scheduler::GetInstance()->Run();
}


void Robot::TestPeriodic() {}


#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif


void Write2Dashboard(void)
{

    frc::SmartDashboard::PutNumber("L_Motor",  Robot::m_drivetrain.GetLeftMotor()  );
    frc::SmartDashboard::PutNumber("R_Motor",  Robot::m_drivetrain.GetRightMotor()  );

    frc::SmartDashboard::PutNumber("D_L_Y_axis",  Robot::m_oi.GetDriverGamepad()->GetRawAxis(GAMEPADMAP_AXIS_L_Y)  );
    frc::SmartDashboard::PutNumber("D_R_Y_axis",  Robot::m_oi.GetDriverGamepad()->GetRawAxis(GAMEPADMAP_AXIS_R_Y)  );
    frc::SmartDashboard::PutNumber("D_L_X_axis",  Robot::m_oi.GetDriverGamepad()->GetRawAxis(GAMEPADMAP_AXIS_L_X)  );
    frc::SmartDashboard::PutNumber("D_R_X_axis",  Robot::m_oi.GetDriverGamepad()->GetRawAxis(GAMEPADMAP_AXIS_R_X)  );

    // frc::SmartDashboard::PutNumber("D_L_Trig",    Robot::m_oi->GetDriverGamepad()->GetRawAxis(GAMEPADMAP_AXIS_L_TRIG)  );
    // frc::SmartDashboard::PutNumber("D_R_Trig",    Robot::m_oi->GetDriverGamepad()->GetRawAxis(GAMEPADMAP_AXIS_R_TRIG)  );

	frc::SmartDashboard::PutNumber("LeftEnc",    Robot::m_drivetrain.GetLeftEncoder());
    frc::SmartDashboard::PutNumber("LeftEnc2",    Robot::m_drivetrain.GetLeftEncoder2());
	frc::SmartDashboard::PutNumber("RightEnc",   Robot::m_drivetrain.GetRightEncoder());  
	frc::SmartDashboard::PutNumber("RightEnc2",    Robot::m_drivetrain.GetRightEncoder2());


	frc::SmartDashboard::PutBoolean("navx_IsConn", Robot::m_drivetrain.IsGyroConnected() );
	frc::SmartDashboard::PutNumber("navx_Yaw",     Robot::m_drivetrain.GetGyroYaw() );
   	frc::SmartDashboard::PutNumber("navx_Angle",   Robot::m_drivetrain.GetGyroAngle() );
 
    // frc::SmartDashboard::PutNumber("navx_Rate",    Robot::m_drivetrain->GetGyroRate() );

    frc::SmartDashboard::PutNumber("Curr_X",    Robot::m_odometry.GetX() );
    frc::SmartDashboard::PutNumber("Curr_Y",    Robot::m_odometry.GetY() );
    frc::SmartDashboard::PutNumber("Curr_Vel",  Robot::m_odometry.GetVel() );
    

    //Time
    //frc::SmartDashboard::PutNumber("FPGATime2",  Robot::m_timer->GetFPGATimestamp() );   //(double) sec
    //frc::SmartDashboard::PutNumber("FPGATime1",  frc::Timer::GetFPGATimestamp() );   //(double) sec
    //frc::SmartDashboard::PutNumber("Timer",      Robot::m_timer->Get() );                //Manual Timer sec
}