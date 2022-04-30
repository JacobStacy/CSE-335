/**
 * @file BezierEnd.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_BEZIEREND_H
#define CANADIANEXPERIENCE_BEZIEREND_H

/**
 * Bezier End Class
 */
class BezierEnd {
private:

    /// Position
    wxPoint mPosition = wxPoint(0, -300);

    /// Rotation
    double mRotation = 0;

    /// Speed
    double mSpeed = 0;

public:

    BezierEnd() {}

    /// Copy Constructor (Disabled)
    BezierEnd(const BezierEnd &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const BezierEnd &) = delete;


    /**
     * Get Position
     * @return Position
     */
    virtual wxPoint GetPosition() { return mPosition; }

    /**
     * Set Position
     * @param x X
     * @param y Y
     */
    void SetPosition(double x, double y) { mPosition.x = x; mPosition.y = y;}

    /**
     * Get Rotation
     * @return Rotation
     */
    double GetRotation() { return mRotation; }

    /**
     * Set Rotation
     * @param rot Rotation
     */
    void SetRotation(double rot) { mRotation = rot; }

    /**
     * Get speed
     * @return Speed
     */
    double GetSpeed() { return mSpeed; }

    /**
     * Get speed
     * @param speed Speed
     */
    void SetSpeed(double speed) { mSpeed = speed; }

};

#endif //CANADIANEXPERIENCE_BEZIEREND_H
