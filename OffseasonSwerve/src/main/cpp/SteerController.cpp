#include "SteerController.h"
#include "Constants.h"

SteerController::SteerController(int motorID, int EncoderPort, double AngleOffset):
    motor(motorID),
    encoder{EncoderPort},
    motorControlMode{ctre::phoenix::motorcontrol::ControlMode::Position}
{
    motor.SetSelectedSensorPosition(Deg2Rad(360-(fmod(((encoder.GetVoltage() * ENCODER_VOLTAGE_TO_DEGREE) + (360-AngleOffset)), 360))) / STEER_ENCODER_POSITION_CONSTANT);
}

double SteerController::GetReferenceAngle() {return referenceAngleRadians;}

double SteerController::GetStateAngle(){ //gets the current angle of the motor
    double motorAngleRadians = motor.GetSelectedSensorPosition() * STEER_ENCODER_POSITION_CONSTANT;
    motorAngleRadians = fmod(motorAngleRadians, 2.0 * M_PI);
    if(motorAngleRadians < 0.0){
        motorAngleRadians += 2.0 * M_PI;
    }
    return motorAngleRadians;
}

void SteerController::SetReferenceAngle(double referenceAngleRadians){
    double currentAngleRadians = motor.GetSelectedSensorPosition() * STEER_ENCODER_POSITION_CONSTANT;

    double currentAngleRadiansMod = fmod(currentAngleRadians, (2.0 * M_PI));
    // if(currentAngleRadiansMod < 0.0){
    //     currentAngleRadiansMod += 2.0 * M_PI;
    // }

    // The reference angle has the range [0, 2pi) but the Falcon's encoder can go above that
    double adjustedReferenceAngleRadians = referenceAngleRadians + currentAngleRadians - currentAngleRadiansMod;
    // if(referenceAngleRadians - currentAngleRadiansMod > M_PI){
    //     adjustedReferenceAngleRadians -= 2.0 * M_PI;
    // } else if (referenceAngleRadians - currentAngleRadiansMod < -M_PI) {
    //     adjustedReferenceAngleRadians += 2.0 * M_PI;
    // }

    motor.Set(motorControlMode, ((adjustedReferenceAngleRadians / STEER_ENCODER_POSITION_CONSTANT))); //FIX maybe subtract a zero angle instead
    //referenceAngleRadians = referenceAngleRadians; //FIX maybe is assigned the adjusted reference angle?
    // DebugOutF("angle: " + std::to_string((adjustedReferenceAngleRadians)/*-(currentAngleRadians)*/));
    // DebugOutF("angleDeg: " + std::to_string( Rad2Deg((adjustedReferenceAngleRadians)/*-(currentAngleRadians)*/)));
    // DebugOutF("TarEnc: " + std::to_string((adjustedReferenceAngleRadians / STEER_ENCODER_POSITION_CONSTANT)/*-(currentAngleRadians/STEER_ENCODER_POSITION_CONSTANT)*/));
    // DebugOutF("CurEnc: " + std::to_string(motor.GetSelectedSensorPosition()));
}