/**
 * @file FishCarp.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef AQUARIUM_FISHCARP_H
#define AQUARIUM_FISHCARP_H

#include "Item.h"
#include "Fish.h"

/**
 * Class for our carp fish
 */
class FishCarp : public Fish {
private:

public:
    /// Default constructor (disabled)
    FishCarp() = delete;

    /// Copy constructor (disabled)
    FishCarp(const FishCarp &) = delete;

    /// Assignment operator
    void operator=(const FishCarp &) = delete;

    FishCarp(Aquarium* aquarium);

    void Spawn(Aquarium*) override;

    wxXmlNode* XmlSave(wxXmlNode* node) override;
};

#endif //AQUARIUM_FISHCARP_H