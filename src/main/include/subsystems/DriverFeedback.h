#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"


//RGB values for LED colors
//                 red, green, blue
#define YELLOW_rgb  0.6, 0.2, 0.0
#define ORANGE_rgb  0.9, 0.1, 0.0
#define GREEN_rgb   0.0, 1.0, 0.0
#define RED_rgb     1.0, 0.0, 0.0
#define BLUE_rgb    0.0, 0.0, 1.0
#define PURPLE_rgb  0.5, 0.0, 0.5



class DriverFeedback : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
    CANifier m_top_canifier{CANIFIER_TOP_CAN_ID};
    CANifier m_bot_canifier{CANIFIER_BOT_CAN_ID};
 public:
  DriverFeedback();
  void InitDefaultCommand() override;
  void UpdateTopLEDs(float,float,float);
  void UpdateBotLEDs(float,float,float);
  void TopLEDsOff(void);
  void BotLEDsOff(void);
  void RumbleOn(void);
  void RumbleOff(void);
};
