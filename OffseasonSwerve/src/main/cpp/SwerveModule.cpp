#include "SwerveModule.h"
#include "Util.h"
#include "Constants.h"

SwerveModule::SwerveModule(int driveID, int steerID, int encoderPort, double angleOffset):
    m_DriveController(driveID), 
    m_SteerController(steerID, encoderPort, angleOffset)
{}

double SwerveModule::GetDriveVelocity(){
    return m_DriveController.GetStateVelocity();
}

double SwerveModule::GetSteerAngle(){
    return m_SteerController.GetStateAngle();
}

void SwerveModule::BreakMode(bool on){
    m_DriveController.BreakMode(on);
}

void SwerveModule::Set(double driveVoltage, double steerAngle){
    steerAngle = Deg2Rad(steerAngle);
    steerAngle = fmod(steerAngle, (2.0 * M_PI)); 
    if(steerAngle < 0.0){
        steerAngle += 2.0 * M_PI;
    }

    double difference = steerAngle - GetSteerAngle();
    // Change the target angle so the difference is in the range [-pi, pi) instead of [0, 2pi)
    if (difference >= M_PI) {
        steerAngle -= 2.0 * M_PI;
    } else if (difference < -M_PI) {
        steerAngle += 2.0 * M_PI;
    }
    difference = steerAngle - GetSteerAngle(); // Recalculate difference
    
    // If the difference is greater than 90 deg or less than -90 deg the drive can be inverted so the total
    // movement of the module is less than 90 deg
    if (difference > M_PI / 2.0 || difference < -M_PI / 2.0) {
        // Only need to add 180 deg here because the target angle will be put back into the range [0, 2pi)
        steerAngle += M_PI;
        driveVoltage *= -1.0;
    }

    // Put the target angle back into the range [0, 2pi)
    steerAngle = fmod(steerAngle, (2.0 * M_PI));
    if (steerAngle < 0.0) {
        steerAngle += 2.0 * M_PI;
    }

    // DebugOutF("Set() steer angle rad: " + std::to_string(steerAngle));
    // DebugOutF("Set() steer angle deg: " + std::to_string(Rad2Deg(steerAngle)));
    // DebugOutF("Set() steer angle ticks: " + std::to_string((steerAngle / STEER_ENCODER_POSITION_CONSTANT)));

    m_DriveController.SetReferenceVoltage(driveVoltage);
    m_SteerController.SetReferenceAngle(steerAngle);
}