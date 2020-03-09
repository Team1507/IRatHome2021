#include "commands/AutoJustShoot.h"
#include "commands/CmdSetShooterVelocity.h"
#include "commands/CmdSetFeederVelocity.h"
#include "commands/CmdSetFeederPower.h"
#include "commands/CmdExtendRamp.h"
#include "commands/CmdSetCarouselPower.h"
#include "commands/CmdRetractRamp.h"
#include "commands/CmdStopCarousel.h"
#include "commands/CmdStopFeeder.h"
#include "subsystems/Shooter.h"
#include "commands/CmdPrintAutoText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdAdjustHood.h"
#include "commands/CmdStopShooter.h"
#include "commands/CmdDriveFwdGyro.h"
#include "commands/CmdDriveFwdGyroV2.h"
#include "commands/CmdDriveRevGyroV2.h"
#include "Commands/CmdWaitStopped.h"


AutoJustShoot::AutoJustShoot() 
{
    AddSequential( new CmdDriveClearAll());
    AddSequential( new CmdPrintAutoText("****** CMD JUST SHOOT ******"));

    //Spool up shooter and get ready to shoot
    AddSequential( new CmdAdjustHood(LINE_HOOD_ANGLE));
    AddSequential( new CmdSetCarouselPower(CAROUSEL_IDLE_POWER));
    AddSequential( new CmdSetShooterVelocity(SHOOTER_IDLE_VELOCITY));

    //AddSequential( new CmdWaitStopped(1.0));
    //Back up off line
    AddSequential( new CmdWaitStopped(0.1));
    AddSequential(new CmdDriveRevGyroV2( 0.2, 0.0, 18, true,true, 0.0));

    AddSequential( new CmdSetShooterVelocity(SHOOTER_AUTO_LINE_VELOCITY));
    AddSequential( new CmdWaitStopped(2.0));

    //so anyway, I started blastin'
    AddSequential( new CmdSetCarouselPower(CAROUSEL_SHOOTING_POWER)); 
    AddSequential( new CmdSetFeederPower(FEEDER_SHOOTING_POWER)); 
    AddSequential( new CmdExtendRamp());
    AddSequential( new CmdWaitStopped(3.0));

    //Stop shooter, feeder, retract ramp
    AddSequential( new CmdStopFeeder());    
    AddSequential( new CmdRetractRamp());
    AddSequential( new CmdStopShooter());
    AddSequential( new CmdAdjustHood(HOME_HOOD_ANGLE));
    AddSequential( new CmdSetCarouselPower(CAROUSEL_IDLE_POWER));


    //move off the line;
    //AddSequential( new CmdDriveFwdGyro( 0.4 , 0, 48 , true , 0.0 ) );
    AddSequential( new CmdDriveFwdGyroV2( 0.4 , 0, 72 , true, true , 0.0 ) );   //48+24=72


    AddSequential(new CmdPrintAutoText("AUTO JUST SHOOT DONE"));
}
