#include "subsystems/ControlPanel.h"
#include "Robot.h"

#define DEPLOY_POWER .2
#define RETRACT_POWER .2
#define TURBO_POWERD_DEPLOY .6
#define TURBO_POWERD_RETRACT .5


#define BOTTOM_STATE 0
#define GOING_UP     1
#define HOLDING_TOP  2
#define GOING_DOWN   3

static rev::ColorSensorV3 m_ColorsensorV3{frc::I2C::Port::kOnboard};

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

    frc::SmartDashboard::PutNumber("CtrlPanel State", movementState);
    
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
    return not m_topSwitch.Get(); 
}


bool ControlPanel::isBottomSwitchPress()
{
    return not m_bottomSwitch.Get();
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
    m_deployMotor.Set(-TURBO_POWERD_RETRACT);
}


void ControlPanel::RetractControl()
{
    m_isDeployed = false;
    m_deployMotor.Set(-RETRACT_POWER);
}


void ControlPanel::HoldTopControl()
{
    m_deployMotor.Set(HOLDING_TOP);
}

int ControlPanel::GetColor(){ 
    frc::Color color = m_ColorsensorV3.GetColor();
    double red = color.red;
    double blue = color.blue;
    double green = color.green;


    if(green > .47 && red < .21)
    {
        //the color is green
        return 1;
    }
    if(red > .4)
    {
        //the color is red
        return 2;
    }
    if(green > .5 && red > .27)
    {
        //the color is yellow
        return 3;
    }    
    if(blue > .3)
    {
        //the color is blue
        return 4;
    }
    //dosent see a color
    return 0;
}


void ControlPanel::SpinControl(){}


void ControlPanel::StopControl()
{
    m_deployMotor.Set(0);
}


void ControlPanel::StopSpinControl(){}