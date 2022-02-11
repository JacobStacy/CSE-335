/**
 * @file FishBeta.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef AQUARIUM_FISHBETA_H
#define AQUARIUM_FISHBETA_H

#include "Item.h"
#include "Fish.h"

/**
 * Class for our beta fish
 */
class FishBeta : public Fish {
private:

public:
    /// Default constructor (disabled)
    FishBeta() = delete;

    /// Copy constructor (disabled)
    FishBeta(const FishBeta &) = delete;

    /// Assignment operator
    void operator=(const FishBeta &) = delete;

    FishBeta(Aquarium* aquarium);

    void Spawn(Aquarium*) override;

    wxXmlNode* XmlSave(wxXmlNode* node) override;
};

#endif //AQUARIUM_FISHBETA_H