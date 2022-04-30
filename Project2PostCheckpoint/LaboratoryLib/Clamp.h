/**
 * @file Clamp.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CLAMP_H
#define CANADIANEXPERIENCE_CLAMP_H

#include "BezierEnd.h"

/**
 * Clamp Class
 */
class Clamp : public BezierEnd {
private:


public:

    Clamp(double x, double y, double speed, double rotation);

    /// Copy Constructor (Disabled)
    Clamp(const Clamp &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Clamp &) = delete;

};

#endif //CANADIANEXPERIENCE_CLAMP_H
