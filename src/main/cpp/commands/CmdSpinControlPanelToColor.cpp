#include "commands/CmdSpinControlPanelToColor.h"
#include "Robot.h"
#include "subsystems/ControlPanel.h"
#include "frc/smartdashboard/SmartDashboard.h"

CmdSpinControlPanelToColor::CmdSpinControlPanelToColor( double wantedColor ) 
{
    m_wantedColor = wantedColor;
}

void CmdSpinControlPanelToColor::Initialize() 
{
    Robot::m_controlPanel.SpinControl();
    m_onColor = false;
}

void CmdSpinControlPanelToColor::Execute() 
{
    m_color = Robot::m_controlPanel.GetColor();

    if (m_color == m_wantedColor)
    {
        m_onColor = true;
    }
    std::cout<<m_onColor<<std::endl;
}

bool CmdSpinControlPanelToColor::IsFinished() 
{
    return m_onColor;
}

void CmdSpinControlPanelToColor::End() 
{
    Robot::m_controlPanel.StopSpinControl();
}

void CmdSpinControlPanelToColor::Interrupted() 
{
    End();
}
