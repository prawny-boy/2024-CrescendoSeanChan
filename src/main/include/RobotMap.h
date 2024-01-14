#pragma once
#include "mag.h"
#include "Wombat.h"

#include <frc/XboxController.h>
#include <frc/DigitalInput.h>

struct RobotMap {
  frc::XboxController driver{0};
  frc::XboxController codriver{1};

  struct Mag {
    rev::CANSparkMax magMotor{99, rev::CANSparkMax::MotorType::kBrushless};
    wom::VoltageController magMotorGroup = wom::VoltageController::Group(magMotor);
    // frc::DigitalInput _switch;
    // wom::CANSparkMaxEncoder magEncoder(&magMotor, 100);
    frc::DigitalInput intakeSensor{0};
    frc::DigitalInput magSensor{1};

    wom::Gearbox magGearbox {
      &magMotorGroup,
      // &magEncoder,
      nullptr,
      wom::DCMotor::NEO(1).WithReduction(1)
    };

    MagConfig config {
       magGearbox,
       &intakeSensor,
       &magSensor
     };
  }; 
  Mag magSystem;
};