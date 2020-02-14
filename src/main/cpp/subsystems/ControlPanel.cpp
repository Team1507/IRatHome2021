#include "subsystems/ControlPanel.h"

#define DEPLOYPOWWER .1
#define RETRACTPOWWER .1
#define TURBOPOWERDEPOLYPOWER .5
#define TURBOPOWERRETRACTPOWER .5

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

void ControlPanel::TURBODeployControl()
{
    m_isDeployed = true;
    m_deployMotor.Set(TURBOPOWERDEPOLYPOWER);
}

void ControlPanel::DeployControl()
{
    m_isDeployed = true;
    m_deployMotor.Set(DEPLOYPOWWER);
}

void ControlPanel::TURBORetractControl()
{
    m_isDeployed = false;
    m_deployMotor.Set(TURBOPOWERRETRACTPOWER);
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