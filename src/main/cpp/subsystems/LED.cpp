#include "subsystems/LED.h"
#include <frc/AddressableLED.h>

LED::LED() : Subsystem("LED") 
{
    m_led.SetLength(kLEDLength);
    m_led.SetData(m_ledbuffer);
    m_led.Start();
}


void LED::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}


void LED::SetAllLEDColor(int r, int g, int b)
{
    for(int i = 0; i < kLEDLength; i++)
    {
        m_ledbuffer[i].SetRGB( r, g, b);
    }

        m_led.SetData(m_ledbuffer);

}


void LED::SetOneLEDColor(int LEDNum, int r, int g, int b)
{
    m_ledbuffer[LEDNum].SetRGB( r, g, b);
    m_led.SetData(m_ledbuffer);
}

//wpi::ArrayRef<frc::AddressableLED::LEDData> leddata[24];
//frc::AddressableLED::LEDData leddata[24];