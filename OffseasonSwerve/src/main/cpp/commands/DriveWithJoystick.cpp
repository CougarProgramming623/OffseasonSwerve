#include "commands/DriveWithJoystick.h"
#include "Robot.h"
#include "frc/kinematics/ChassisSpeeds.h"

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
    frc::Rotation2d rot = frc::Rotation2d();
    // r->GetDriveTrain().BaseDrive(
    //     frc::ChassisSpeeds::FromFieldRelativeSpeeds(
    //         r->GetJoyStick().GetRawAxis(0) * r->GetDriveTrain().kMAX_VELOCITY_METERS_PER_SECOND,
    //         r->GetJoyStick().GetRawAxis(1) * r->GetDriveTrain().kMAX_VELOCITY_METERS_PER_SECOND,
    //         r->GetJoyStick().GetRawAxis(2) * r->GetDriveTrain().kMAX_VELOCITY_METERS_PER_SECOND,
    //         //r->getYaw()
    //     )
    // );

    r->GetDriveTrain().BaseDrive(
        frc::ChassisSpeeds::FromFieldRelativeSpeeds(
            units::meters_per_second_t(r->GetJoyStick().GetRawAxis(0) * r->GetDriveTrain().kMAX_VELOCITY_METERS_PER_SECOND),
            units::meters_per_second_t(r->GetJoyStick().GetRawAxis(1) * r->GetDriveTrain().kMAX_VELOCITY_METERS_PER_SECOND),
            units::radians_per_second_t(r->GetJoyStick().GetRawAxis(2) * r->GetDriveTrain().kMAX_ANGULAR_VELOCITY_RADIANS_PER_SECOND),
            rot
        )
    );
}