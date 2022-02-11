/**
 * @file FishNemo.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef AQUARIUM_FISHNEMO_H
#define AQUARIUM_FISHNEMO_H

#include "Item.h"
#include "Fish.h"

/**
 * Class for our nemo fish
 */
class FishNemo : public Fish {
private:

public:
    /// Default constructor (disabled)
    FishNemo() = delete;

    /// Copy constructor (disabled)
    FishNemo(const FishNemo &) = delete;

    /// Assignment operator
    void operator=(const FishNemo &) = delete;

    FishNemo(Aquarium* aquarium);

    void Spawn(Aquarium*) override;

    wxXmlNode* XmlSave(wxXmlNode* node) override;
};

#endif //AQUARIUM_FISHNEMO_H