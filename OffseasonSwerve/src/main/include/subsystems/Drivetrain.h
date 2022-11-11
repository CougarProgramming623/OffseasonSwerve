#pragma once

#include <ctre/phoenix/motorcontrol/can/TalonFX.h>



//copied includes
#include <frc/geometry/Transform2d.h>
#include <frc/geometry/Translation2d.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/kinematics/SwerveDriveOdometry.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/controller/PIDController.h>
#include <frc/controller/ProfiledPIDController.h>
#include <frc/trajectory/TrapezoidProfile.h>
#include <frc/controller/HolonomicDriveController.h>
#include <frc/filter/SlewRateLimiter.h>
#include <frc/Timer.h>
#include <units/angle.h>
#include <units/length.h>
#include <units/angular_velocity.h>
#include <units/velocity.h>
#include <units/angular_acceleration.h>
#include <units/math.h>
#include <wpi/numbers>
#include <array>
#include <fstream>
#include <map>
#include <algorithm>
#include <frc/Timer.h>




#include "./Util.h"
#include "Robot.h"
#include "Constants.h"
//#include "./commands/DriveWithJoystick.h"




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

 private:
  frc2::Button m_DriveButton;
  frc2::Button m_FODToggle;

  frc::frc::Translation2d::Translation2d m_FrontLeftLocation;
  frc::frc::Translation2d::Translation2d m_frontRightLocation;
  frc::frc::Translation2d::Translation2d m_backLeftLocation;
  frc::frc::Translation2d::Translation2d m_backRightLocation;
  frc::SwerveDriveKinematics<4> m_kinematics;



  const double kMAX_VOLTAGE = 12.0; //FIX

  //how fast the robot should be able to drive
  const double kMAX_VELOCITY_METERS_PER_SECOND = 6380.0 / 60.0 * /*DriveReduction * WheelDiameter*/ *  M_PI;
  
  //theoretical maximum angular velocity - can be replaced with measure amount
  const double kMAX_ANGULAR_VELOCITY_RADIANS_PER_SECOND = kMAX_VELOCITY_METERS_PER_SECOND / std::sqrt(std::pow(DRIVETRAIN_TRACKWIDTH_METERS / 2), 2) + std::pow(DRIVETRAIN_WHEELBASE_METERS / 2), 2));
};