/**
 * @file DecorCastle.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef AQUARIUM_DECORCASTLE_H
#define AQUARIUM_DECORCASTLE_H

#include "Item.h"


/**
 * Class for the Decor Castle
 */
class DecorCastle : public Item {
private:

public:
    /// Default constructor (disabled)
    DecorCastle() = delete;

    /// Copy constructor (disabled)
    DecorCastle(const DecorCastle &) = delete;

    /// Assignment operator
    void operator=(const DecorCastle &) = delete;

    DecorCastle(Aquarium* aquarium);

    void Spawn(Aquarium*) override;

    wxXmlNode* XmlSave(wxXmlNode* node) override;
};


#endif //AQUARIUM_DECORCASTLE_H
