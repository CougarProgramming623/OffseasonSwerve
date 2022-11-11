#pragma once


class SteerController {
    public:
        double GetReferenceAngle();
        double GetStateAngle();

        void SetReferenceAngle(double referenceAngleRadians);
        void SetBreakMode(bool on);
};