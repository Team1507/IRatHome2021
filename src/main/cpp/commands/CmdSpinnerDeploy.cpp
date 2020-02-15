#include "subsystems/ControlPanel.h"
#include "Robot.h"
#include "commands/CmdSpinnerDeploy.h"


CmdSpinnerDeploy::CmdSpinnerDeploy() 
{
    Requires(&Robot::m_controlPanel);
    m_hasTurbo = false;
    m_isMoving = false;
}

void CmdSpinnerDeploy::Initialize() {}

void CmdSpinnerDeploy::Execute() 
{ 
    //these are to take care of my laziness and because I don't want mile long ifs
    bool bottomLS   = Robot::m_controlPanel.isBottomSwitchPress();
    bool topLS      = Robot::m_controlPanel.isTopSwitchPress();

    if(bottomLS && !Robot::m_controlPanel.GetIsDeployed() && !m_hasTurbo)
    {
        Robot::m_controlPanel.TURBODeployControl(); //won't change the state of 'm_isDeployed'
        m_hasTurbo = true;// this is really just a bad name for a flag
        m_isMoving = true;//this one is a much better name and should prolly be put in the deploy functions
    }
    else if(!bottomLS && !Robot::m_controlPanel.GetIsDeployed() && m_hasTurbo)
    {
        Robot::m_controlPanel.DeployControl();
        m_hasTurbo = false;
    }
    else if(topLS && Robot::m_controlPanel.GetIsDeployed() && m_hasTurbo)
    {
        Robot::m_controlPanel.TURBORetractControl();
        m_hasTurbo = true; 
        m_isMoving = true;
    } 
    else if(!topLS && m_hasTurbo && Robot::m_controlPanel.GetIsDeployed())
    {
        Robot::m_controlPanel.RetractControl();
        m_hasTurbo = false;
    }

    if((topLS||bottomLS) && !m_hasTurbo && m_isMoving)
    {
        Robot::m_controlPanel.StopControl();
        m_isMoving = false;
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
    End();
}
