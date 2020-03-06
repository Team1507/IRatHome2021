#include "commands/AutoBallAtTrench.h"
#include "frc/commands/WaitCommand.h"
#include "commands/CmdDriveManual.h"
#include "commands/CmdDriveVelRampTest.h"
#include "commands/CmdPrintAutoText.h"
#include "commands/CmdDriveFwdEncoder.h"
#include "commands/CmdDriveFwdGyro.h"
#include "commands/CmdDriveFwdGyroV2.h"
#include "commands/CmdDriveRevEncoder.h"
#include "commands/CmdDriveRevGyro.h"
#include "commands/CmdDriveRevGyroV2.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveTurn2Angle.h"
#include "commands/CmdSetIntake.h"
#include "commands/CmdTurnToLimelight.h"
#include "commands/CmdSetFeederVelocity.h"
#include "commands/CmdSetFeederPower.h"
#include "commands/CmdSetCarouselPower.h"
#include "commands/CmdSetShooterVelocity.h"
#include "commands/CmdStopShooter.h"
#include "commands/CmdExtendRamp.h"
#include "commands/CmdRetractRamp.h"
#include "commands/CmdStopFeeder.h"
#include "commands/CmdStopCarousel.h"
#include "commands/CmdAdjustHood.h"
#include "subsystems/Shooter.h"


AutoBallAtTrench::AutoBallAtTrench() 
{
  	AddSequential(new CmdPrintAutoText("AUTO BALL AT TRENCH"));
    AddSequential(new CmdDriveClearAll());
    //AddSequential(new CmdLoggingEnable(true));
    //CmdDriveRevGyro(double power, double heading, double distance, bool stop, double timeout
    
    //***************************************************
    AddSequential(new CmdSetIntake( true ));

    AddSequential(new CmdAdjustHood(TRENCH_HOOD_ANGLE));

    AddSequential(new CmdSetShooterVelocity(SHOOTER_TRENCH_VELOCITY));

    AddSequential(new CmdSetCarouselPower(CAROUSEL_IDLE_POWER));

    //AddSequential(new CmdDriveRevGyro( 0.4, 0.0, 138, true, 0.0));//was 132
    AddSequential(new CmdDriveRevGyroV2( 0.4, 0.0, 132, true,true, 0.0));//was 132

    AddSequential(new frc::WaitCommand(0.1));

    //AddSequential(new CmdDriveFwdGyro( 0.4, -5.0, 40, true, 0.0));  //was 28
    AddSequential(new CmdDriveFwdGyroV2( 0.4, -5.0, 28, true,true, 0.0));  //was 28

    //power, angle
    AddSequential(new CmdDriveTurn2Angle(.15, -10));
    
    AddSequential(new CmdTurnToLimelight() );

    //SHOOT!!!!!!

    AddSequential(new CmdSetCarouselPower(CAROUSEL_SHOOTING_POWER));

    AddSequential(new CmdSetFeederPower(FEEDER_SHOOTING_POWER));

    AddSequential(new CmdExtendRamp());

    AddSequential(new frc::WaitCommand(5.0));

    //Done Shooting
    AddSequential(new CmdStopFeeder());
    AddSequential(new CmdRetractRamp());
    AddSequential(new CmdStopShooter());

    AddSequential(new CmdStopCarousel());

    // AddSequential(new CmdDriveTurn2Angle( 0.15, -15.0  ));
}
