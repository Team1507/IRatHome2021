#include "subsystems/ControlPanel.h"
#include "Robot.h"
#include "commands/CmdSpinnerDeploy.h"


CmdSpinnerDeploy::CmdSpinnerDeploy() 
{
    Requires(&Robot::m_controlPanel);
}

void CmdSpinnerDeploy::Initialize() {}

void CmdSpinnerDeploy::Execute() 
{ 
    static bool Direction;
    static bool DidTurbo;
    if(Robot::m_controlPanel.isBottomSwitchPress() && DidTurbo == false)
    {
        Robot::m_controlPanel.TURBODeployControl();
        Direction = true;
        DidTurbo = true;
        
        //true going up
        //false going down
    }
    else if(!Robot::m_controlPanel.isBottomSwitchPress() && Direction == true)
    {
        Robot::m_controlPanel.DeployControl();
    }
    else if(Robot::m_controlPanel.isTopSwitchPress() && DidTurbo == false)
    {
        Robot::m_controlPanel.TURBORetractControl();
        Direction = false;
        DidTurbo = true;
    }
    else if(!Robot::m_controlPanel.isTopSwitchPress() && Direction == false)
    {
        Robot::m_controlPanel.RetractControl();
    }
}


bool CmdSpinnerDeploy::IsFinished()
{
    if(Robot::m_controlPanel.GetIsDeployed() && Robot::m_controlPanel.isTopSwitchPress()) return true;
    if(!Robot::m_controlPanel.GetIsDeployed() && Robot::m_controlPanel.isBottomSwitchPress()) return true;
    return false;
}


void CmdSpinnerDeploy::End() 
{
    Robot::m_controlPanel.StopControl();
}

void CmdSpinnerDeploy::Interrupted() 
{
    Robot::m_controlPanel.StopControl();
}
