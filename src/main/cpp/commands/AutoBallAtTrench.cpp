#include "commands/AutoBallAtTrench.h"
#include "frc/commands/WaitCommand.h"
#include "commands/CmdDriveManual.h"
#include "commands/CmdDriveVelRampTest.h"
#include "commands/CmdPrintAutoText.h"
#include "commands/CmdDriveFwdEncoder.h"
#include "commands/CmdDriveFwdGyro.h"
#include "commands/CmdDriveRevEncoder.h"
#include "commands/CmdDriveRevGyro.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveTurn2Angle.h"
#include "commands/CmdSetIntake.h"
#include "commands/CmdTurnToLimelight.h"
#include "commands/CmdSetFeederVelocity.h"
#include "commands/CmdSetFeederPower.h"
#include "commands/CmdSetCarouselPower.h"
#include "commands/CmdSetShooterVelocity.h"
#include "commands/CmdStopShooter.h"
#include "commands/CmdStopFeeder.h"
#include "commands/CmdStopCarousel.h"
#include "subsystems/Shooter.h"


AutoBallAtTrench::AutoBallAtTrench() 
{
  	AddSequential(new CmdPrintAutoText("AUTO BALL AT TRENCH"));
    AddSequential(new CmdDriveClearAll());
    //AddSequential(new CmdLoggingEnable(true));
    //CmdDriveRevGyro(double power, double heading, double distance, bool stop, double timeout
    
    //***************************************************
    AddSequential(new CmdSetIntake( true ));

    AddSequential(new CmdSetShooterVelocity(SHOOTER_IDLE_VELOCITY));

    AddSequential(new CmdSetCarouselPower(CAROUSEL_IDLE_POWER));

    AddSequential(new CmdDriveRevGyro( 0.4, 0.0, 150, true, 0.0));

    AddSequential(new CmdDriveFwdGyro( 0.2, 0.0, 200, true, 0.0));

    //power, angle
    AddSequential(new CmdDriveTurn2Angle(.5, -10));
    
    AddSequential(new CmdTurnToLimelight() );

    AddSequential(new CmdSetShooterVelocity(SHOOTER_TRENCH_VELOCITY));

    AddSequential(new CmdSetCarouselPower(CAROUSEL_SHOOTING_POWER));

    //AddSequential(new CmdSetFeederVelocity(FEEDER_SHOOTING_VELOCITY));
    AddSequential(new CmdSetFeederPower(FEEDER_SHOOTING_POWER));

    AddSequential(new frc::WaitCommand(10.0));

    AddSequential(new CmdStopFeeder());

    AddSequential(new CmdStopShooter());

    AddSequential(new CmdStopCarousel());

    // AddSequential(new CmdDriveTurn2Angle( 0.15, -15.0  ));
}
