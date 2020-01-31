/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoDriveStr8.h"
#include "commands/CmdDriveFwdGyro.h"

AutoDriveStr8::AutoDriveStr8() 
{
  AddSequential(new CmdDriveFwdGyro(0.2, 0.0, 75, true, 0.0));
}
