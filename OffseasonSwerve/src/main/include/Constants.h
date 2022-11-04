// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

#define ROBOT_WHEELBASE

#ifdef ROBOT_WHEELBASE


#define DRIVETRAIN_TRACKWIDTH_METERS = 0.5644; // FIXME Measure and set trackwidth
    /**
     * The front-to-back distance between the drivetrain wheels.
     *
     * Should be measured from center to center.
     */
    #define DRIVETRAIN_WHEELBASE_METERS = 0.666; // FIXME Measure and set wheelbase

    #define FRONT_LEFT_MODULE_DRIVE_MOTOR = 0; // FIXME Set front left module drive motor ID
    #define FRONT_LEFT_MODULE_STEER_MOTOR = 0; // FIXME Set front left module steer motor ID
    #define FRONT_LEFT_MODULE_STEER_ENCODER = 0; // FIXME Set front left steer encoder ID
    #define FRONT_LEFT_MODULE_STEER_OFFSET = -Deg2Rad(0.0); // FIXME Measure and set front left steer offset

    #define FRONT_RIGHT_MODULE_DRIVE_MOTOR = 0; // FIXME Set front right drive motor ID
    #define FRONT_RIGHT_MODULE_STEER_MOTOR = 0; // FIXME Set front right steer motor ID
    #define FRONT_RIGHT_MODULE_STEER_ENCODER = 0; // FIXME Set front right steer encoder ID
    #define FRONT_RIGHT_MODULE_STEER_OFFSET = -Deg2Rad(0.0); // FIXME Measure and set front right steer offset

    #define BACK_LEFT_MODULE_DRIVE_MOTOR = 0; // FIXME Set back left drive motor ID
    #define BACK_LEFT_MODULE_STEER_MOTOR = 0; // FIXME Set back left steer motor ID
    #define BACK_LEFT_MODULE_STEER_ENCODER = 0; // FIXME Set back left steer encoder ID
    #define BACK_LEFT_MODULE_STEER_OFFSET = -Deg2Rad(0.0); // FIXME Measure and set back left steer offset

    #define BACK_RIGHT_MODULE_DRIVE_MOTOR = 0; // FIXME Set back right drive motor ID
    #define BACK_RIGHT_MODULE_STEER_MOTOR = 0; // FIXME Set back right steer motor ID
    #define BACK_RIGHT_MODULE_STEER_ENCODER = 0; // FIXME Set back right steer encoder ID
    #define BACK_RIGHT_MODULE_STEER_OFFSET = -Deg2Rad(0.0); // FIXME Measure and set back right steer offset
#endif