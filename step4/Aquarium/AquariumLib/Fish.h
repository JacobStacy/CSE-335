/**
 * @file Fish.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef AQUARIUM_FISH_H
#define AQUARIUM_FISH_H

#include "Item.h"

/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
class Fish : public Item {
private:
    /// Fish speed in the X direction
    /// in pixels per second
    double mSpeedX;

    /// Fish speed in the Y direction
    /// in pixels per second
    double mSpeedY;

protected:
    Fish(Aquarium* aquarium, const std::wstring& filename);

public:
    /// Default constructor (disabled)
    Fish() = delete;

    /// Copy constructor (disabled)
    Fish(const Fish &) = delete;


/// Assignment operator
    void operator=(const Fish &) = delete;

    void Update(double elapsed);

    /**
     * Sets fish's speed in the x axis
     * @param speed speed in the x axis
     */
    void SetSpeedX(double speed) { mSpeedX = speed; }

    /**
     * Sets fish's speed in the y axis
     * @param speed speed in the y axis
     */
    void SetSpeedY(double speed) { mSpeedY = speed; }

    wxXmlNode* XmlSave(wxXmlNode* node) override;

    void XmlLoad(wxXmlNode* node) override;
};

#endif //AQUARIUM_FISH_H
