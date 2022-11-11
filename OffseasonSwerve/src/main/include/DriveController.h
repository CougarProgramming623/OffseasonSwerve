#pragma once

#include <ctre/phoenix/motorcontrol/NeutralMode.h>
//#include <ctre/phoenix/motorcontrol/StatusFrame>
//#include <ctre/phoenix/motorcontrol/TalonFXControlMode.h>
//#include <ctre/phoenix/motorcontrol/TalonFXInvertType.h>
#include <ctre/phoenix/motorcontrol/can/TalonFX.h>
//#include <ctre/phoenix/motorcontrol/can/TalonFXConfiguration.h>

using ctre::phoenix::motorcontrol::can::TalonFX;

class DriveController {
    public:
        DriveController(int ID, double sensorVelocityCoefficient);

        void setReferenceVoltage(double voltage);

        double getStateVelocity();
    private:
        TalonFX motor;
        const double sensorVelocityCoefficient;

        double nominalVoltage;  //it is double.NaN in the java and i still dont know what that means
        double currentLimit;    //it is double.NaN in the java and i still dont know what that means


};  