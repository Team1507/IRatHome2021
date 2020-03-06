#include "commands/AutoTrenchToLine.h"

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
#include "commands/CmdStopFeeder.h"
#include "commands/CmdExtendRamp.h"
#include "commands/CmdRetractRamp.h"
#include "commands/CmdStopCarousel.h"
#include "commands/CmdAdjustHood.h"
#include "Commands/CmdWaitStopped.h"

AutoTrenchToLine::AutoTrenchToLine() 
{
    AddSequential(new CmdPrintAutoText("AUTO TRENCH TO LINE"));
    AddSequential(new CmdDriveClearAll());
    //AddSequential(new CmdLoggingEnable(true));
    //CmdDriveRevGyro(double power, double heading, double distance, bool stop, double timeout
    
    //***************************************************
    AddSequential(new CmdSetIntake( true ));
    AddSequential(new CmdAdjustHood(LINE_HOOD_ANGLE));
    AddSequential(new CmdSetShooterVelocity(SHOOTER_IDLE_VELOCITY));
    AddSequential(new CmdSetCarouselPower(CAROUSEL_IDLE_POWER));

    //AddSequential(new CmdDriveRevGyro( 0.4, 0.0, 132, true, 0.0));
    AddSequential(new CmdDriveRevGyroV2( 0.4, 0.0, 132, true, true, 0.0));
    AddSequential(new CmdWaitStopped(0.1));

    //Hit 'em with that uno reverse card
    //AddSequential(new CmdDriveFwdGyro(.4, -5.0, 40, false, 0.0));         //drive forward at an angle to avoid hitting wall
    AddSequential(new CmdDriveFwdGyroV2(.4, -5.0, 40, true, false, 0.0));   //drive forward at an angle to avoid hitting wall
    

    //Start spooling up shooter
    AddSequential(new CmdSetShooterVelocity(SHOOTER_LINE_VELOCITY));


    AddSequential(new CmdDriveFwdGyroV2(.4, -82.0, 72, false, false, 0.0));     //Major turn left towards target

    
    //Turn toward target
    AddSequential(new CmdDriveFwdGyroV2(.4, 25.0, 60, false, false, 0.0));      //Turn towards target
    AddSequential(new CmdDriveFwdGyroV2(.4, 0,     6, false, true, 0.0));       //Move up a little


    AddSequential(new CmdWaitStopped(1.0));
    AddSequential(new CmdTurnToLimelight());

    //so anyway i started blastin
    AddSequential(new CmdSetShooterVelocity(SHOOTER_LINE_VELOCITY));
    AddSequential(new CmdSetCarouselPower(CAROUSEL_SHOOTING_POWER));
    AddSequential(new CmdSetFeederPower(FEEDER_SHOOTING_POWER));
    
    AddSequential(new CmdExtendRamp());

    //** SHOOT Time
    AddSequential(new CmdWaitStopped(6.0));

    //Clean up
    AddSequential(new CmdSetIntake( false ));
    AddSequential(new CmdRetractRamp());
    AddSequential(new CmdStopFeeder());
    AddSequential(new CmdStopShooter());

    AddSequential(new CmdAdjustHood(HOME_HOOD_ANGLE));

    //Done Shooting
    AddSequential(new CmdStopFeeder());
    AddSequential(new CmdRetractRamp());
    AddSequential(new CmdStopShooter());
    AddSequential(new CmdAdjustHood(HOME_HOOD_ANGLE));
    AddSequential(new CmdSetCarouselPower(CAROUSEL_IDLE_POWER));
    

    AddSequential(new CmdPrintAutoText("AUTO TRENCH TO LINE DONE"));

}
