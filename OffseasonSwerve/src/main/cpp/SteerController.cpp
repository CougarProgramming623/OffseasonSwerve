#include "SteerController.h"


SteerController::SteerController(int motorID, int EncoderPort, double motorEncoderPositionCoefficient, double motorEncoderVelocityCoefficient):
    motor(motorID),
    encoder{EncoderPort},
    kMOTOR_ENCODER_POSITION_COEFFICIENT(motorEncoderPositionCoefficient),
    kMOTOR_ENCODER_VELOCITY_COEFFICIENT(motorEncoderVelocityCoefficient)
{}

double SteerController::GetReferenceAngle() {return referenceAngleRadians;}

double SteerController::GetStateAngle(){
    double motorAngleRadians = motor.GetSelectedSensorPosition() * kMOTOR_ENCODER_POSITION_COEFFICIENT;
    motorAngleRadians = fmod(motorAngleRadians, 2.0 * M_PI);
    if(motorAngleRadians < 0.0){
        motorAngleRadians += 2.0 * M_PI;
    }
    return motorAngleRadians;
}

void SteerController::SetReferenceAngle(double referenceAngleRadians){
    double currentAngleRadians = motor.GetSelectedSensorPosition() * kMOTOR_ENCODER_POSITION_COEFFICIENT;

    // Sometimes (~5% of the time) when we initialize, the absolute encoder isn't fully set up, and we don't
    // end up getting a good reading. If we reset periodically this won't matter anymore.
    if(motor.GetSelectedSensorVelocity() * kMOTOR_ENCODER_VELOCITY_COEFFICIENT < kENCODER_RESET_MAX_ANGULAR_VELOCITY){ //FIX
        if(++resetIteration >= kENCODER_RESET_ITERATIONS){
            resetIteration = 0;
            double absoluteAngle = encoder.GetValue() / kENCODER_MAX;
            motor.SetSelectedSensorPosition(absoluteAngle / kMOTOR_ENCODER_POSITION_COEFFICIENT);
            currentAngleRadians = absoluteAngle;
        } else {
            resetIteration = 0;
        }
    }

    double currentAngleRadiansMod = fmod(currentAngleRadians, (2.0 * M_PI));
    if(currentAngleRadiansMod < 0.0){
        currentAngleRadiansMod += 2.0 * M_PI;
    }

    // The reference angle has the range [0, 2pi) but the Falcon's encoder can go above that
    double adjustedReferenceAngleRadians = referenceAngleRadians + currentAngleRadians - currentAngleRadiansMod;
    if(referenceAngleRadians - currentAngleRadiansMod > M_PI){
        adjustedReferenceAngleRadians -= 2.0 * M_PI;
    } else if (referenceAngleRadians - currentAngleRadiansMod < -M_PI) {
        adjustedReferenceAngleRadians += 2.0 * M_PI;
    }

    motor.Set(motorControlMode, adjustedReferenceAngleRadians / kMOTOR_ENCODER_POSITION_COEFFICIENT);
    SteerController::referenceAngleRadians = referenceAngleRadians; //IDK IF THIS WORKS
}