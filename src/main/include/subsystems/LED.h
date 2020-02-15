#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/AddressableLED.h>


class LED : public frc::Subsystem 
{
 private:

    static const int kLEDLength = 36;
    static const int kLEDPWMPort = 9;

    frc::AddressableLED m_led{kLEDPWMPort};

    std::array < frc::AddressableLED::LEDData, kLEDLength > m_ledbuffer;
  
 public:
    LED();
    void InitDefaultCommand() override;

    //Our Funtions
    void SetAllLEDColor( int r, int g, int b);
    void SetOneLEDColor( int LEDNum, int r2, int g2, int b2);
    
};
