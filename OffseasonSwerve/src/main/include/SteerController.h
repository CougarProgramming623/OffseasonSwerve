#pragma once
#include "Util.h"

#include <ctre/phoenix/motorcontrol/NeutralMode.h>
#include <ctre/phoenix/motorcontrol/can/TalonFX.h>


using ctre::phoenix::motorcontrol::can::TalonFX;
using ctre::phoenix::motorcontrol::ControlMode;

class SteerController {
    public:
        double GetReferenceAngle();
        double GetStateAngle();

        void SetReferenceAngle(double referenceAngleRadians);
    private:
        TalonFX motor;
        ControlMode motorControlMode;
        
        //AbsoluteEncoder absoluteEncoder

        const double    kMOTOR_ENCODER_POSITION_COEFFICIENT;
        const double    kMOTOR_ENCODER_VELOCITY_COEFFICIENT;
        const int       kENCODER_RESET_ITERATIONS = 500;
        const double    kENCODER_RESET_MAX_ANGULAR_VELOCITY = Deg2Rad(0.5); //make sure this works

        double referenceAngleRadians;
        double resetIteration;

};