#include "commands/AutoJustShoot.h"
#include "commands/CmdSetShooterVelocity.h"
#include "commands/CmdSetFeederVelocity.h"
#include "commands/CmdExtendRamp.h"
#include "frc/commands/WaitCommand.h"
#include "commands/CmdSetCarouselPower.h"
#include "commands/CmdRetractRamp.h"
#include "commands/CmdStopCarousel.h"
#include "commands/CmdStopFeeder.h"
#include "subsystems/Shooter.h"


AutoJustShoot::AutoJustShoot() 
{
    //Spool up shooter
    AddSequential( new CmdSetShooterVelocity(SHOOTER_IDLE_VELOCITY)); 
    AddSequential( new frc::WaitCommand(2.0));

        
    //start shooter, feeder, and extend ramp
    AddSequential( new CmdSetShooterVelocity(SHOOTER_LINE_VELOCITY));
    AddSequential( new frc::WaitCommand(2.0));
    

    //so anyway, I started blastin'
    AddSequential( new CmdSetCarouselPower(CAROUSEL_SHOOTING_POWER)); 
    AddSequential( new CmdSetFeederVelocity(FEEDER_SHOOTING_VELOCITY)); 
    AddSequential( new CmdExtendRamp());
    AddSequential( new frc::WaitCommand(5.0));

    
    //Stop shooter, feeder, retract ramp
    AddSequential( new CmdStopCarousel());
    AddSequential( new CmdStopFeeder());
    AddSequential( new CmdSetShooterVelocity(SHOOTER_IDLE_VELOCITY)); 
    AddSequential( new CmdRetractRamp());

}
