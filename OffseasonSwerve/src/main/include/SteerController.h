#pragma once


class SteerController {
    public:
        double getReferenceAngle();

        void setReferenceAngle(double referenceAngleRadians);

        double getStateAngle();
};