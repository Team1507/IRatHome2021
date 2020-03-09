#include "Robot.h"
#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/AddressableLED.h>
#include <frc/DriverStation.h>

#include "subsystems/Shooter.h"
#include "subsystems/Intake.h"
#include "subsystems/DriverFeedback.h"
#include "subsystems/ControlPanel.h"

#include "commands/AutoDoNothing.h"
#include "commands/AutoDriveStr8.h"
#include "commands/AutoJustShoot.h"
#include "commands/AutoBallAtTrench.h"
#include "commands/AutoTrenchToLine.h"
#include "subsystems/LED.h"
#include "subsystems/Climber.h"
#include "subsystems/Drivetrain.h"


Drivetrain Robot::m_drivetrain;
Odometry   Robot::m_odometry;
frc::Timer Robot::m_timer;

Shooter Robot::m_shooter;
Intake Robot::m_intake;
ControlPanel Robot::m_controlPanel;
BallDeflector Robot::m_ballDeflector;
LED Robot::m_led;
Climber Robot::m_climber;

PowerDistributionPanel Robot::m_pdp {PDP_CAN_ID};

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
    m_drivetrain.HardResetEncoders();
    m_drivetrain.ZeroGyro();
    m_climber.ClearClimbActivated();    //just to set the value to false before anything haappens

    //Auto Chooser
    m_chooser.SetDefaultOption("Default Auto", new AutoDoNothing()    );
    //m_chooser.AddOption("Auto Drive Str8",     new AutoDriveStr8()    );    //untested
    m_chooser.AddOption("Auto Just Shoot",     new AutoJustShoot()    );
    m_chooser.AddOption("Auto Ball at trench", new AutoBallAtTrench() );
    m_chooser.AddOption("Auto Trench to line", new AutoTrenchToLine() );
    
    frc::SmartDashboard::PutData("Auto Modes", &m_chooser);


    //Set LED's to Yellow initially
    m_led.SetAllLEDColor(255,255,0);

    frc::SmartDashboard::PutNumber( "LimelightOffset", -1.5 ); //calibrated 2/21  was -1.25


}


void Robot::RobotPeriodic() 
{
    //m_odometry.OdometryPeriodic();
    m_shooter.ShooterPeriodic();
    Write2Dashboard();


}


void Robot::DisabledInit() 
{
    std::cout<<"Disabled Init"<<std::endl;

    m_shooter.SetShooterVelocity(0);
    m_climber.ClearClimbActivated();

}


void Robot::DisabledPeriodic() 
{   
    frc::Scheduler::GetInstance()->Run(); 
}


void Robot::AutonomousInit() 
{
    std::cout<<"Auto Init"<<std::endl;

    if(m_ds.GetAlliance() == DriverStation::kRed)
    {
        m_led.SetAllLEDColor(255, 0, 0);
    }
    else if(m_ds.GetAlliance() == DriverStation::kBlue)
    {
        m_led.SetAllLEDColor(0,0,255);
    }
    else
    {
        m_led.SetAllLEDColor(255,255,0);
    }



    m_autonomousCommand = m_chooser.GetSelected();
    if (m_autonomousCommand != nullptr) { m_autonomousCommand->Start();   }
}


void Robot::AutonomousPeriodic() { frc::Scheduler::GetInstance()->Run(); }


void Robot::TeleopInit() 
{
    std::cout<<"Teleop Init"<<std::endl;
    m_shooter.SetCarouselIdlePower();


    if(m_ds.GetAlliance() == DriverStation::kRed)
    {
        m_led.SetAllLEDColor(255, 0, 0);
    }
    else if(m_ds.GetAlliance() == DriverStation::kBlue)
    {
        m_led.SetAllLEDColor(0,0,255);
    }
    else
    {
        m_led.SetAllLEDColor(255,255,0);
    }


    //Make sure Auto is not running in Teleop
    if (m_autonomousCommand != nullptr) 
    {
        m_autonomousCommand->Cancel();
        m_autonomousCommand = nullptr;
    }
}


void Robot::TeleopPeriodic() 
{ 

    m_intake.IntakePeriodic();
    m_controlPanel.ControlPanelPeriodic();
    m_climber.ClimberPeriodic();
    
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

    // frc::SmartDashboard::PutNumber("D_L_Y_axis",  Robot::m_oi.GetDriverGamepad()->GetRawAxis(GAMEPADMAP_AXIS_L_Y)  );
    // frc::SmartDashboard::PutNumber("D_R_Y_axis",  Robot::m_oi.GetDriverGamepad()->GetRawAxis(GAMEPADMAP_AXIS_R_Y)  );
    // frc::SmartDashboard::PutNumber("D_L_X_axis",  Robot::m_oi.GetDriverGamepad()->GetRawAxis(GAMEPADMAP_AXIS_L_X)  );
    // frc::SmartDashboard::PutNumber("D_R_X_axis",  Robot::m_oi.GetDriverGamepad()->GetRawAxis(GAMEPADMAP_AXIS_R_X)  );

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

    // frc::SmartDashboard::PutNumber("Curr_X",    Robot::m_odometry.GetX() );
    // frc::SmartDashboard::PutNumber("Curr_Y",    Robot::m_odometry.GetY() );
    // frc::SmartDashboard::PutNumber("Curr_Vel",  Robot::m_odometry.GetVel() );
    
    //limit switch
    frc::SmartDashboard::PutBoolean("CP Top LS", Robot::m_controlPanel.isTopSwitchPress());
    frc::SmartDashboard::PutBoolean("CP Bottom LS", Robot::m_controlPanel.isBottomSwitchPress());

    //Shooter
    frc::SmartDashboard::PutNumber("DBG Shooter Velocity",  Robot::m_shooter.GetShooterVelocity() );
    frc::SmartDashboard::PutNumber("DBG Shooter Power",     Robot::m_shooter.GetShooterPower() );

    //Time
    //frc::SmartDashboard::PutNumber("FPGATime2",  Robot::m_timer->GetFPGATimestamp() );   //(double) sec
    //frc::SmartDashboard::PutNumber("FPGATime1",  frc::Timer::GetFPGATimestamp() );   //(double) sec
    //frc::SmartDashboard::PutNumber("Timer",      Robot::m_timer->Get() );                //Manual Timer sec
    //LEDS BAYBEE

    //I don't know why - we can't read currents from the PDP.  Phoenix Tuner shows all channels as 0.00
    // frc::SmartDashboard::PutNumber("CAROUSEL CURRENT", Robot::m_pdp.GetCurrent(CAROUSEL_PDP_CHANNEL));
    // frc::SmartDashboard::PutNumber("12v DISTRIBUTOR CURRENT", Robot::m_pdp.GetCurrent(TWELVE_VOLT_DISTRIBUTOR));
    // frc::SmartDashboard::PutNumber("PDP Voltage", Robot::m_pdp.GetVoltage() );

    Robot::m_drivetrain.WriteFalconTemps();
    Robot::m_shooter.WriteFalconTemps();
}