#pragma once

#include <ctre/phoenix/motorcontrol/can/TalonFX.h>

#include "./Util.h"
#include "Robot.h"
#include "Constants.h"

#include "./commands/DriveWithJoystick.h"
// #include <frc2/command/Command.h>
// #include <frc2/command/InstantCommand.h>
// #include <frc2/command/SubsystemBase.h>
// #include <frc2/command/button/Button.h>

using ctre::phoenix::motorcontrol::can::TalonFX;

class DriveTrain : public frc2::SubsystemBase {
 public:
  DriveTrain();
  void BaseDrive(double power);
  void DriveInit();
  void BreakMode(bool on);


  void UseVelocityPID();
  void UseMagicPID();
  void UsePostionPID();
  void SetPID(double E, double P, double I, double D, double F);

  void DriveToPosition(double x);

  inline TalonFX& GetFrontL() { return m_FrontLeft; }
  inline TalonFX& GetFrontR() { return m_FrontRight; }
  inline TalonFX& GetBackL() { return m_BackLeft; }
  inline TalonFX& GetBackR() { return m_BackRight; }

 private:
  TalonFX m_FrontLeft;
  TalonFX m_FrontRight;
  TalonFX m_BackLeft;
  TalonFX m_BackRight;

  frc2::Button m_DriveButton;
  frc2::Button m_FODToggle;

  frc::SwerveDriveKinematics<4> m_kinematics{mfrontLeftLocation, m_frontRightLocation, m_backLeftLocation, m_backRightLocation};

  const double kMAX_VOLTAGE = 12.0; //FIX

  //how fast the robot should be able to drive
  const double kMAX_VELOCITY_METERS_PER_SECOND = 6380.0 / 60.0 * /*DriveReduction * WheelDiameter*/ *  M_PI;
  
  //theoretical maximum angular velocity - can be replaced with measure amount
  const double kMAX_ANGULAR_VELOCITY_RADIANS_PER_SECOND = kMAX_VELOCITY_METERS_PER_SECOND / std::sqrt(std::pow(DRIVETRAIN_TRACKWIDTH_METERS / 2), 2) + std::pow(DRIVETRAIN_WHEELBASE_METERS / 2), 2));
};