#pragma once

#include "DriveController.h"
#include "SteerController.h"


class SwerveModule {
    public:
        SwerveModule(int driveID, double driveSensorVelocityCoefficient, 
                     int steerID, int encoderPort, double steerEncoderPositionCoefficient,
                     double steerEncoderVelocityCoefficient);

        double GetDriveVelocity();

        double GetSteerAngle();

        void Set(double driveVoltage, double steerAngle);
        void BreakMode(bool on);
    
    private:
        DriveController m_DriveController;
        SteerController m_SteerController;
};
