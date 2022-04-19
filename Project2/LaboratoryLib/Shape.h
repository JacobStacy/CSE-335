/**
 * @file Shape.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_SHAPE_H
#define CANADIANEXPERIENCE_SHAPE_H


#include "Component.h"
#include "Polygon.h"

class Shape : public Component{
private:

    wxPoint mOrigin;

    cse335::Polygon mPolygon;

public:

    Shape(const std::wstring &name);

    /// Copy Constructor (Disabled)
    Shape(const Shape &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Shape &) = delete;

    /**
     * Destructor
    */
    virtual ~Shape() = default;
    

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    cse335::Polygon* GetPolygon() { return &mPolygon; }

    void SetOrigin(double x, double y) { mOrigin.x = x; mOrigin.y = y; }

    wxPoint GetOrigin() { return mOrigin; }

};

#endif //CANADIANEXPERIENCE_SHAPE_H
