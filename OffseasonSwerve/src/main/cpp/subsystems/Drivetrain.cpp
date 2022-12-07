#include "subsystems/Drivetrain.h"

#include <frc/trajectory/Trajectory.h>
#include <frc/kinematics/SwerveModuleState.h>

DriveTrain::DriveTrain()
    : m_FrontLeftLocation(units::meter_t (DRIVETRAIN_TRACKWIDTH_METERS / 2.0), units::meter_t (DRIVETRAIN_WHEELBASE_METERS / 2.0)),
      m_FrontRightLocation(units::meter_t (DRIVETRAIN_TRACKWIDTH_METERS / 2.0), units::meter_t (-DRIVETRAIN_WHEELBASE_METERS / 2.0)),
      m_BackLeftLocation(units::meter_t (-DRIVETRAIN_TRACKWIDTH_METERS / 2.0), units::meter_t (DRIVETRAIN_WHEELBASE_METERS / 2.0)),
      m_BackRightLocation(units::meter_t (-DRIVETRAIN_TRACKWIDTH_METERS / 2.0), units::meter_t (-DRIVETRAIN_WHEELBASE_METERS / 2.0)),
      m_Kinematics(m_FrontLeftLocation, m_FrontRightLocation, m_BackLeftLocation, m_BackRightLocation),
      m_Rotation(),
      m_FrontLeftModule(FRONT_LEFT_MODULE_DRIVE_MOTOR, FRONT_LEFT_MODULE_STEER_MOTOR, FRONT_LEFT_MODULE_ENCODER_PORT, -137),
      m_FrontRightModule(FRONT_RIGHT_MODULE_DRIVE_MOTOR, FRONT_RIGHT_MODULE_STEER_MOTOR, FRONT_RIGHT_MODULE_ENCODER_PORT, -287),
      m_BackLeftModule(BACK_LEFT_MODULE_DRIVE_MOTOR, BACK_LEFT_MODULE_STEER_MOTOR, BACK_LEFT_MODULE_ENCODER_PORT, -140.6),
      m_BackRightModule(BACK_RIGHT_MODULE_DRIVE_MOTOR, BACK_RIGHT_MODULE_STEER_MOTOR, BACK_RIGHT_MODULE_ENCODER_PORT, -2),
      m_ChassisSpeeds{0_mps, 0_mps, 0_rad_per_s}
{}

void periodic(){
  auto [fl, fr, bl, br] = m_Kinematics.ToSwerveModuleStates(m_ChassisSpeeds);
  frc::SwerveModuleState states[4] = {fl, fr, bl, br};
  m_Kinematics.DesaturateWheelSpeeds(fl, fr, bl, br);

  m_FrontLeftModule.Set(states[0].speed / kMAX_VELOCITY_METERS_PER_SECOND * kMAX_VOLTAGE, (double) states[0].angle.Radians());
  m_FrontRightModule.Set(states[1].speed / kMAX_VELOCITY_METERS_PER_SECOND * kMAX_VOLTAGE, (double) states[1].angle.Radians());
  m_BackLeftModule.Set(states[2].speed / kMAX_VELOCITY_METERS_PER_SECOND * kMAX_VOLTAGE, (double) states[2].angle.Radians());
  m_BackRightModule.Set(states[3].speed / kMAX_VELOCITY_METERS_PER_SECOND * kMAX_VOLTAGE, (double) states[3].angle.Radians());
}

void DriveTrain::BaseDrive(ChassisSpeeds chassisSpeeds){
  m_ChassisSpeeds = chassisSpeeds;
}
void DriveTrain::DriveInit(){}

void DriveTrain::BreakMode(bool on){
  m_FrontLeftModule.BreakMode(true);
  m_FrontRightModule.BreakMode(true);
  m_BackLeftModule.BreakMode(true);
  m_BackRightModule.BreakMode(true);
}
