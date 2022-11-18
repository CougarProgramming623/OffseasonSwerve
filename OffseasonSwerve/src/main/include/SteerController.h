#pragma once

#include "Util.h"

#include <ctre/phoenix/motorcontrol/NeutralMode.h>
#include <ctre/phoenix/motorcontrol/can/TalonFX.h>
#include <frc/AnalogInput.h>


using ctre::phoenix::motorcontrol::can::TalonFX;
using ctre::phoenix::motorcontrol::ControlMode;

class SteerController {
    public:
        SteerController(int motorID, int EncoderPort, double motorEncoderPositionCoefficient, double motorEncoderVelocityCoefficient);

        double GetReferenceAngle();
        double GetStateAngle();

        void SetReferenceAngle(double referenceAngleRadians);

        TalonFX motor;
        ControlMode motorControlMode;
        
        frc::AnalogInput encoder;

        const double kMOTOR_ENCODER_POSITION_COEFFICIENT;
        const double kMOTOR_ENCODER_VELOCITY_COEFFICIENT;
        const int kENCODER_MAX = 1250; //IDK IF THIS IS THE MAX ENCODER VALUE OR NOT 
        const int kENCODER_RESET_ITERATIONS = 500; //IDK WHY WE HAVE THIS
        const double kENCODER_RESET_MAX_ANGULAR_VELOCITY = Deg2Rad(0.5); //IDK WHY WE HAVE THIS

        double referenceAngleRadians;
        double resetIteration;

};