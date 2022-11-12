#include "subsystems/Drivetrain.h"

DriveTrain::DriveTrain()
    : m_FrontLeftLocation(units::meter_t (DRIVETRAIN_TRACKWIDTH_METERS / 2.0), units::meter_t (DRIVETRAIN_WHEELBASE_METERS / 2.0)),
      m_FrontRightLocation(units::meter_t (DRIVETRAIN_TRACKWIDTH_METERS / 2.0), units::meter_t (-DRIVETRAIN_WHEELBASE_METERS / 2.0)),
      m_BackLeftLocation(units::meter_t (-DRIVETRAIN_TRACKWIDTH_METERS / 2.0), units::meter_t (DRIVETRAIN_WHEELBASE_METERS / 2.0)),
      m_BackRightLocation(units::meter_t (-DRIVETRAIN_TRACKWIDTH_METERS / 2.0), units::meter_t (-DRIVETRAIN_WHEELBASE_METERS / 2.0)),
      m_Kinematics(m_FrontLeftLocation, m_FrontRightLocation, m_BackLeftLocation, m_BackRightLocation),
      m_FrontLeftModule(FRONT_LEFT_MODULE_DRIVE_MOTOR, 1, FRONT_LEFT_MODULE_STEER_MOTOR, FRONT_LEFT_MODULE_ENCODER_PORT, 1, 1),
      m_FrontRightModule(FRONT_RIGHT_MODULE_DRIVE_MOTOR, 1, FRONT_RIGHT_MODULE_STEER_MOTOR, FRONT_LEFT_MODULE_ENCODER_PORT, 1, 1),
      m_BackLeftModule(BACK_LEFT_MODULE_DRIVE_MOTOR, 1, BACK_LEFT_MODULE_STEER_MOTOR, BACK_LEFT_MODULE_ENCODER_PORT, 1, 1),
      m_BackRightModule(BACK_RIGHT_MODULE_DRIVE_MOTOR, 1, BACK_RIGHT_MODULE_STEER_MOTOR, BACK_RIGHT_MODULE_ENCODER_PORT, 1, 1)
{}
void DriveTrain::BaseDrive(double power){}
void DriveTrain::DriveInit(){}
void DriveTrain::BreakMode(bool on){}

// void DriveTrain::UseVelocityPID(){}
// void DriveTrain::UseMagicPID(){}
// void DriveTrain::UsePostionPID(){}
// void DriveTrain::SetPID(double E, double P, double I, double D, double F){}

// void DriveTrain::DriveToPosition(double x){}
