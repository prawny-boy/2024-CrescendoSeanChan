#pragma once
 
#include "Wombat.h"
#include "Mag.h"
#include <frc/XboxController.h>
 
class MagManualControl : public behaviour::Behaviour {
 public:
  explicit MagManualControl(Mag *mag, frc::XboxController *codriver);
   
  void OnTick(units::second_t dt) override;
 private:
  Mag *_mag;
  frc::XboxController *_codriver;
  bool _rawControl; // Default of Bool is False.
};

class MagAutoPass : public behaviour::Behaviour {
 public:
  explicit MagAutoPass(Mag *mag);
   
  void OnTick(units::second_t dt) override;
 private:
  Mag *_mag;
};

class MagAutoHold : public behaviour::Behaviour {
 public:
  explicit MagAutoHold(Mag *mag);
   
  void OnTick(units::second_t dt) override;
 private:
  Mag *_mag;
};
