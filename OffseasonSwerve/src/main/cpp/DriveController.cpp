#include "DriveController.h"
#include "Constants.h"

using ctre::phoenix::motorcontrol::ControlMode;
using ctre::phoenix::motorcontrol::NeutralMode;

DriveController::DriveController(int ID, double sensorVelocityCoefficient)
:
    motor(ID),
    kSENSOR_VELOCITY_COEFCIENT(sensorVelocityCoefficient)
{
    motor.SetNeutralMode(NeutralMode::Brake);
    //motor.SetInverted(SMTH)                           IDK why but some of them rotate clockwise and others counter clockwise
    motor.SetSensorPhase(true);                         //also dont know why we do this one
}

void  DriveController::SetReferenceVoltage(double voltage){
    motor.Set(ControlMode::PercentOutput, voltage / nominalVoltage);
}   

double DriveController::GetStateVelocity(){
    return motor.GetSelectedSensorVelocity() * kSENSOR_VELOCITY_COEFCIENT;
}

void DriveController::BreakMode(bool on){
    if(on)
        motor.SetNeutralMode(NeutralMode::Brake);
    else    
        motor.SetNeutralMode(NeutralMode::Coast);
}
