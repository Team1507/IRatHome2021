#include "commands/AutoTrenchToLine.h"

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
#include "commands/CmdExtendRamp.h"
#include "commands/CmdRetractRamp.h"
#include "commands/CmdStopCarousel.h"
#include "commands/CmdAdjustHood.h"

AutoTrenchToLine::AutoTrenchToLine() 
{
    AddSequential(new CmdPrintAutoText("AUTO TRENCH TO LINE"));
    AddSequential(new CmdDriveClearAll());
    //AddSequential(new CmdLoggingEnable(true));
    //CmdDriveRevGyro(double power, double heading, double distance, bool stop, double timeout
    
    //***************************************************
    AddSequential(new CmdSetIntake( true ));
    AddSequential(new CmdAdjustHood(LINE_HOOD_ANGLE));
    AddSequential(new CmdSetShooterVelocity(SHOOTER_TRENCH_VELOCITY));
    AddSequential(new CmdSetCarouselPower(CAROUSEL_IDLE_POWER));
    AddSequential(new CmdDriveRevGyro( 0.4, 0.0, 132, true, 0.0));
    AddSequential(new frc::WaitCommand(0.1));

    //Hit 'em with that uno reverse card

    AddSequential(new CmdDriveFwdGyro(.4, -5.0, 40, false, 0.0));//drive forward at an angle to avoid hitting wall

    
    AddSequential(new CmdDriveFwdGyro(.4, -82.0, 55, false, 0.0));//drive forward a distance at an angle
   // AddSequential(new CmdDriveTurn2Angle(.2, 0)); //realign facing the thingy
    //Turn2Angle not working.  Why???
    
    AddSequential(new CmdDriveFwdGyro(.4, 25.0, 60, true, 0.0));

    AddSequential(new frc::WaitCommand(1.0));
    AddSequential(new CmdTurnToLimelight());

    //so anyway i started blastin
    AddSequential(new CmdSetShooterVelocity(SHOOTER_LINE_VELOCITY));
    AddSequential(new CmdSetCarouselPower(CAROUSEL_SHOOTING_POWER));
    AddSequential(new CmdSetFeederPower(FEEDER_SHOOTING_POWER));
    
    AddSequential(new CmdExtendRamp());

    //** SHOOT Time
    AddSequential(new frc::WaitCommand(6.0));

    //Clean up
    AddSequential(new CmdSetIntake( false ));
    AddSequential(new CmdRetractRamp());
    AddSequential(new CmdStopFeeder());
    AddSequential(new CmdStopShooter());
    AddSequential(new CmdStopCarousel());
    AddSequential(new CmdAdjustHood(HOME_HOOD_ANGLE));

    AddSequential(new CmdPrintAutoText("AUTO TRENCH TO LINE DONE"));

}
