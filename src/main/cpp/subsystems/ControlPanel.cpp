#include "subsystems/ControlPanel.h"
#include "Robot.h"

#define DEPLOY_POWER .1
#define RETRACT_POWER .1
#define TURBO_POWERD_DEPLOY .5
#define TURBO_POWERD_RETRACT .5


#define BOTTOM_STATE 0
#define GOING_UP     1
#define HOLDING_TOP  2
#define GOING_DOWN   3


ControlPanel::ControlPanel() : Subsystem("ExampleSubsystem") 
{
    m_isDeployed = false;     
}


void ControlPanel::ControlPanelPeriodic()
{

    static int movementState = 0;

    bool botLS    = isBottomSwitchPress();
    bool topLS    = isTopSwitchPress();
    bool isButton = Robot::m_oi.GetOperatorGamepad()->GetRawButton(GAMEPADMAP_BUTTON_A);
    
    switch (movementState)
    {
    case BOTTOM_STATE:  //this state brings it back to the bottom
        if(isButton)
        {
            movementState = GOING_UP;//start moving up
        }

        break;
    
    case GOING_UP:
        if(botLS) 
        {
            TURBODeployControl();
        }
        else if(topLS)
        {
            movementState = HOLDING_TOP;
        }        
        else if(!botLS)
        {
            DeployControl();
        }

        if(!isButton) 
        {
            movementState = GOING_DOWN;
        }
        break;
    case HOLDING_TOP:
        if(!topLS) 
        {
            movementState = GOING_UP;
        }
        if(!isButton) 
        {
            movementState = GOING_DOWN;
        }
        HoldTopControl();
        break;
    case GOING_DOWN:
        if(topLS)
        {
            TURBORetractControl();
        }
        else if(botLS)
        {
            movementState = BOTTOM_STATE;
        }        
        else if(!topLS)
        {
            RetractControl();
        }

        if(isButton) 
        {
            movementState = GOING_UP;
        }
        break;
    default:
        std::cout<<"SOS!!!!!"<<std::endl;
        break;
    }
}


bool ControlPanel::GetIsDeployed()
{
    return m_isDeployed;
}


void ControlPanel::InitDefaultCommand() {}


bool ControlPanel::isTopSwitchPress()
{
    return m_topSwitch.Get(); 
}


bool ControlPanel::isBottomSwitchPress()
{
    return m_bottomSwitch.Get();
}


void ControlPanel::TURBODeployControl()
{
    //m_isDeployed = true;
    m_deployMotor.Set(TURBO_POWERD_DEPLOY);
}


void ControlPanel::DeployControl()
{
    m_isDeployed = true;
    m_deployMotor.Set(DEPLOY_POWER);
}


void ControlPanel::TURBORetractControl()
{
    //m_isDeployed = false;
    m_deployMotor.Set(TURBO_POWERD_RETRACT);
}


void ControlPanel::RetractControl()
{
    m_isDeployed = false;
    m_deployMotor.Set(RETRACT_POWER);
}


void ControlPanel::HoldTopControl()
{
    m_deployMotor.Set(HOLDING_TOP);
}

int ControlPanel::GetColor(){}


void ControlPanel::SpinControl(){}


void ControlPanel::StopControl()
{
    m_deployMotor.Set(0);
}


void ControlPanel::StopSpinControl(){}