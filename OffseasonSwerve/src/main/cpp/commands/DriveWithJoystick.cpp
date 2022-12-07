#include "commands/DriveWithJoystick.h"
#include "Robot.h"

DriveWithJoystick::DriveWithJoystick() {
    this->AddRequirements(&Robot::GetRobot()->GetDriveTrain());
}

void Initialize(){

}

double deadFix(double in, double deadband) {
    if(abs(in) < deadband) {
        return 0;
    }
    return in;
}



void Execute() {
    Robot* r = Robot::GetRobot();
    
    //r->GetDriveTrain().BaseDrive();
}