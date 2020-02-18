#include "commands/CmdSpin3Times.h"
#include "Robot.h"
#include <iostream>
#include "frc/smartdashboard/SmartDashboard.h"

#define GREEN   1
#define RED     2
#define YELLOW  3
#define BLUE    4

CmdSpin3Times::CmdSpin3Times() {}

void CmdSpin3Times::Initialize() 
{
    Robot::m_controlPanel.SpinControl();
    m_isGreen = false;
    m_isBlue = false;
    m_isRed = false;
    m_isYellow = false;
    m_numberBlueFalsecounts = 0;
    m_numberBlueTruecounts = 0;
    m_numberGreenFalsecounts = 0;
    m_numberGreenTruecounts = 0;
    m_numberRedFalsecounts = 0;
    m_numberRedTruecounts = 0;
    m_numberYellowFalsecounts = 0;
    m_numberYellowTruecounts = 0;
    m_spins = 0;
}

void CmdSpin3Times::Execute()
{
    std::cout<<m_spins<<std::endl;
    m_color = Robot::m_controlPanel.GetColor();

    //*****************************COLORS**************************
    if ( m_color == GREEN )
    {
        if (m_numberGreenTruecounts >= 6 )
        {
            if (!m_isGreen)
            {
                m_spins++;
                m_isGreen = true;
                m_numberGreenFalsecounts = 0;
                // std::cout<<"GREEN!"<<std::endl;

                m_numberBlueTruecounts = 0;
                m_numberYellowTruecounts = 0;
                m_numberRedTruecounts = 0;

                m_isYellow = false;
                m_isBlue = false;
                m_isRed = false;
            }
            // std::cout<<m_numberGreenTruecounts<<std::endl;
            m_numberGreenTruecounts ++;
        }
        else
        {
            m_numberGreenTruecounts++;
        }
    }
    if ( m_color == RED )
    {
        if ( m_numberRedTruecounts >= 6 )
        {

            if (!m_isRed)
            {
                m_isRed = true;
                m_isYellow = false;
                m_isBlue = false;
                m_isGreen = false;
                m_numberBlueTruecounts = 0;
                m_numberYellowTruecounts = 0;
                m_numberGreenTruecounts = 0;    
                m_numberRedFalsecounts = 0;
                // std::cout<<"RED!"<<std::endl;                        
            }
            m_numberRedTruecounts ++;
            // std::cout<<m_numberRedTruecounts<<std::endl;

        }
        else
        {
            m_numberRedTruecounts ++;
        }
        
    }
    if ( m_color == YELLOW )
    {
        if ( m_numberYellowTruecounts >= 6 )
        {
            if (!m_isYellow)
            {
                m_isYellow = true;
                m_isBlue = false;
                m_isRed = false;
                m_isGreen = false;
                m_numberBlueTruecounts = 0;
                m_numberGreenTruecounts = 0;
                m_numberRedTruecounts = 0;     
                // std::cout<<"YELLOW!"<<std::endl;    
                m_numberYellowFalsecounts = 0;                               
            }
            m_numberYellowTruecounts ++;
            // std::cout<<m_numberYellowTruecounts<<std::endl;

        }
        else
        {
            m_numberYellowTruecounts ++;
        }
        
    }
    if ( m_color == BLUE )
    {
        if ( m_numberBlueTruecounts >= 5 )
        {
            if (!m_isBlue)
            {
            m_numberBlueFalsecounts = 0;
            // std::cout<<"BLUE!"<<std::endl;
            m_isBlue = true;
            m_isYellow = false;
            m_isRed = false;
            m_isGreen = false;
            m_numberRedTruecounts = 0;
            m_numberYellowTruecounts = 0;
            m_numberRedTruecounts = 0;                
            }
            // std::cout<<m_numberBlueTruecounts<<std::endl;
            m_numberBlueTruecounts ++;
        }
        else
        {
            m_numberBlueTruecounts ++;
        }
        
    }
    //******************************************************************************
    if ( m_color != GREEN )
    {
        if ( m_numberGreenFalsecounts == 3 )
        {
            m_numberGreenTruecounts = 0;
        }
        else
        {
            m_numberGreenFalsecounts ++;            
        }
    }
    if ( m_color != RED )
    {
        if ( m_numberRedFalsecounts == 3 )
        {
            m_numberRedTruecounts = 0;
        }
        else
        {
            m_numberRedFalsecounts ++;            
        }
    }
    if ( m_color != YELLOW )
    {
        if ( m_numberYellowFalsecounts == 3 )
        {
            m_numberYellowTruecounts = 0;
        }
        else
        {
            m_numberYellowFalsecounts ++;            
        }
    }
    if ( m_color != BLUE )
    {
        if ( m_numberBlueFalsecounts == 3 )
        {
            m_numberBlueTruecounts = 0;
        }
        else
        {
            m_numberBlueFalsecounts ++;            
        }
    }
    if (m_color == 0)
    {
        std::cout<<"null"<<std::endl;
    }
}

bool CmdSpin3Times::IsFinished() 
{

    if(m_spins >= 7)
    {
        return true;
    }

    return false;
}

void CmdSpin3Times::End()
{
    Robot::m_controlPanel.StopSpinControl();
}

void CmdSpin3Times::Interrupted() 
{
    End();
}
