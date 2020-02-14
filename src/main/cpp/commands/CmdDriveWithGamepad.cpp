#include "Robot.h"
#include "commands/CmdDriveWithGamepad.h"

CmdDriveWithGamepad::CmdDriveWithGamepad() {
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    Requires(&Robot::m_drivetrain);
}

// Called just before this Command runs the first time
void CmdDriveWithGamepad::Initialize() {  std::cout<<"CmdDriveWithGamepad Started" << std::endl;  }

// Called repeatedly when this Command is scheduled to run
void CmdDriveWithGamepad::Execute() { Robot::m_drivetrain.DriveWithGamepad(); }

// Make this return true when this Command no longer needs to run execute()
bool CmdDriveWithGamepad::IsFinished() { return false; }

// Called once after isFinished returns true
void CmdDriveWithGamepad::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdDriveWithGamepad::Interrupted() { std::cout<<"CmdDriveWithGamepad Interrupted" << std::endl;  }
