// Copyright (c) 2023-2024 CurtinFRC
// Open Source Software, you can modify it according to the terms
// of the MIT License at the root of this project

#pragma once

#include <frc/XboxController.h>

#include "Intake.h"
#include "Wombat.h"

enum class IntakeBehaviourState { kIntaking, kEjecting, kIdleing, kRawControl, kPassing};

class IntakeManualControl : public behaviour::Behaviour {
 public:
  explicit IntakeManualControl(Intake* intake, frc::XboxController& codriver);

  void SetBehaviourState(IntakeBehaviourState behaviourState);
  void OnTick(units::second_t dt) override;

  IntakeBehaviourState GetBehaviourState();

 private:
  Intake* _intake;
  frc::XboxController& _codriver;
  IntakeBehaviourState _behaviourState = IntakeBehaviourState::kIdleing;

  units::volt_t _rawVoltage;
  units::volt_t _setVoltage;
  bool _rawControl = true;
  bool _intaking = false;
  bool _ejecting = false;
  bool _passing = false;
};

class AutoIntake : public behaviour::Behaviour {
 public:
  explicit AutoIntake(Intake* intake);
  void OnTick(units::second_t dt) override;

 private:
  Intake* _intake;
  IntakeBehaviourState _behaviourState = IntakeBehaviourState::kIdleing;
};
