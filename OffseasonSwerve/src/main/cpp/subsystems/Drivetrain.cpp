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
      m_FrontLeftModule(FRONT_LEFT_MODULE_DRIVE_MOTOR, FRONT_LEFT_MODULE_STEER_MOTOR, FRONT_LEFT_MODULE_ENCODER_PORT, 0),
      m_FrontRightModule(FRONT_RIGHT_MODULE_DRIVE_MOTOR, FRONT_RIGHT_MODULE_STEER_MOTOR, FRONT_RIGHT_MODULE_ENCODER_PORT, 73),
      m_BackLeftModule(BACK_LEFT_MODULE_DRIVE_MOTOR, BACK_LEFT_MODULE_STEER_MOTOR, BACK_LEFT_MODULE_ENCODER_PORT, 0), //FIX OFFSET
      m_BackRightModule(BACK_RIGHT_MODULE_DRIVE_MOTOR, BACK_RIGHT_MODULE_STEER_MOTOR, BACK_RIGHT_MODULE_ENCODER_PORT, 0), //FIX OFFSET
      m_ChassisSpeeds{0_mps, 0_mps, 0_rad_per_s}
{}
void DriveTrain::BaseDrive(double power){
  DebugOutF("BR= " + std::to_string(Rad2Deg(m_BackRightModule.m_SteerController.GetStateAngle())));
  //DebugOutF("FR= " + std::to_string(Rad2Deg(m_FrontRightModule.m_SteerController.GetStateAngle())));
  //DebugOutF("BL= " + std::to_string(m_BackLeftModule.m_SteerController.encoder.GetVoltage()));
  //DebugOutF("FL= " + std::to_string(m_FrontLeftModule.m_SteerController.encoder.GetVoltage()));

  //just goes forward slowly
  
  //m_BackRightModule.Set(1,-90);
  /*m_FrontRightModule.Set(1,0);
  m_BackLeftModule.Set(1,0);
  m_BackRightModule.Set(1,0);
  */

  //frc:: SwerveModuleStats states[4] = m_Kinematics.ToSwerveModuleStates(m_ChassisSpeeds);
  //SwerveDriveKinematics.desaturateWheelSpeeds(states, MAX_VELOCITY_METERS_PER_SECOND);

  // m_frontLeftModule.set(states[0].speedMetersPerSecond / MAX_VELOCITY_METERS_PER_SECOND * MAX_VOLTAGE, states[0].angle.getRadians());
  // m_frontRightModule.set(states[1].speedMetersPerSecond / MAX_VELOCITY_METERS_PER_SECOND * MAX_VOLTAGE, states[1].angle.getRadians());
  // m_backLeftModule.set(states[2].speedMetersPerSecond / MAX_VELOCITY_METERS_PER_SECOND * MAX_VOLTAGE, states[2].angle.getRadians());
  // m_backRightModule.set(states[3].speedMetersPerSecond / MAX_VELOCITY_METERS_PER_SECOND * MAX_VOLTAGE, states[3].angle.getRadians());
}
void DriveTrain::DriveInit(){}

void DriveTrain::BreakMode(bool on){
  m_FrontLeftModule.BreakMode(true);
  m_FrontRightModule.BreakMode(true);
  m_BackLeftModule.BreakMode(true);
  m_BackRightModule.BreakMode(true);
}

// void DriveTrain::UseVelocityPID(){}
// void DriveTrain::UseMagicPID(){}
// void DriveTrain::UsePostionPID(){}
// void DriveTrain::SetPID(double E, double P, double I, double D, double F){}

// void DriveTrain::DriveToPosition(double x){}
