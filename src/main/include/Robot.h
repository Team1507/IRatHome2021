#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Timer.h>
#include <iostream>
#include <frc/AddressableLED.h>
#include <frc/DriverStation.h>

#include "GamepadMap.h"
#include "OI.h"

#include "subsystems/Drivetrain.h"
#include "subsystems/Odometry.h"
#include "subsystems/Shooter.h"
#include "subsystems/Intake.h"
#include "subsystems/DriverFeedback.h"
#include "subsystems/BallDeflector.h"
#include "subsystems/ControlPanel.h"
#include "subsystems/LED.h"
#include "subsystems/Climber.h"
#include "frc/PowerDistributionPanel.h"
#include "util/LogFile.h"
 
class Robot : public frc::TimedRobot {
 public:

    static Drivetrain m_drivetrain;
    static Intake m_intake;
    static ControlPanel m_controlPanel;
    static Odometry m_odometry;
    static frc::Timer m_timer;
    static OI m_oi;
    static Shooter m_shooter;
    static DriverFeedback m_driverFeedback;
    static BallDeflector m_ballDeflector;
    static LED m_led;
    static Climber m_climber;
    static LogFile m_logfile;

    static PowerDistributionPanel m_pdp;
   //  static DriverStation m_ds;

    void RobotInit() override;
    void RobotPeriodic() override;
    void DisabledInit() override;
    void DisabledPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;

 private:
    // Have it null by default so that if testing teleop it
    // doesn't have undefined behavior and potentially crash.
    frc::Command* m_autonomousCommand = nullptr;
    frc::SendableChooser<frc::Command*> m_chooser;
};
