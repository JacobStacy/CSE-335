/**
 * @file Cable.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CABLE_H
#define CANADIANEXPERIENCE_CABLE_H

class Clamp;

#include "Component.h"
#include "PowerSource.h"
#include "PowerSink.h"

class Cable : public Component{
private:

    std::vector<std::shared_ptr<Clamp>> mClamps;

    PowerSource mSource;

    PowerSink mSink;

public:




};

#endif //CANADIANEXPERIENCE_CABLE_H
