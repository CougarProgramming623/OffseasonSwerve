#pragma once


class SwerveModule {
    public:
        SwerveModule();

        double getDriveVelocity();

        double getSteerAngle();

        void set(double driveVoltage, double steerAngle);
};
