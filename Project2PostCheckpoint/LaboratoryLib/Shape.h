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

/**
 * Shape Class
 */
class Shape : public Component{
private:

    /// Orgin
    wxPoint mOrigin;

    /// Polygon
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

    /**
     * Gets polygon
     * @return polygon
     */
    cse335::Polygon* GetPolygon() { return &mPolygon; }

    /**
     * Set Origin
     * @param x X
     * @param y Y
     */
    void SetOrigin(double x, double y) { mOrigin.x = x; mOrigin.y = y; }

    /**
     * Returns origin
     * @return Origin
     */
    wxPoint GetOrigin() { return mOrigin; }

};

#endif //CANADIANEXPERIENCE_SHAPE_H
