#include "subsystems/ControlPanel.h"

#define DEPLOYPOWWER .1
#define RETRACTPOWWER .1

ControlPanel::ControlPanel() : Subsystem("ExampleSubsystem") 
{
    m_isDeployed = false;     
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


void ControlPanel::DeployControl()
{
    m_isDeployed = true;
    m_deployMotor.Set(DEPLOYPOWWER);
}


void ControlPanel::RetractControl()
{
    m_isDeployed = false;
    m_deployMotor.Set(RETRACTPOWWER);
}


int ControlPanel::GetColor(){}


void ControlPanel::SpinControl(){}


void ControlPanel::StopControl()
{
    m_deployMotor.Set(0);
}


void ControlPanel::StopSpinControl(){}