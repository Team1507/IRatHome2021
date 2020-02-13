#include "subsystems/ControlPanel.h"
#include "Robot.h"
#include "commands/CmdSpinnerDeploy.h"

CmdSpinnerDeploy::CmdSpinnerDeploy() 
{
    Requires(&Robot::m_controlPanel);
}

void CmdSpinnerDeploy::Initialize() 
{
    if (Robot::m_controlPanel.GetIsDeployed())
    {
        Robot::m_controlPanel.RetractControl();
    }
    else if(!Robot::m_controlPanel.GetIsDeployed())
    {
        Robot::m_controlPanel.DeployControl();
    }
}

void CmdSpinnerDeploy::Execute() {}


bool CmdSpinnerDeploy::IsFinished()
{
    if(Robot::m_controlPanel.GetIsDeployed() && Robot::m_controlPanel.isTopSwitchPress()) return true;
    if(!Robot::m_controlPanel.GetIsDeployed() && Robot::m_controlPanel.isBottomSwitchPress()) return true;
    return false;
}


void CmdSpinnerDeploy::End() 
{
    
}

void CmdSpinnerDeploy::Interrupted() {}
