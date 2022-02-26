/**
 * @file SpartyGnome.h
 * @author matty
 *
 *
 */

#ifndef PROJECT1_SPARTYGNOME_H
#define PROJECT1_SPARTYGNOME_H
#include "Item.h"
#include <memory>

class SpartyGnome : public Item {
private:
    /// Default constructor (disabled)
    SpartyGnome() = delete;

    /// Copy constructor (disabled)
    SpartyGnome(const SpartyGnome &) = delete;

    /// Assignment operator
    void operator=(const SpartyGnome &) = delete;

    ///Constructor
    SpartyGnome(Game *game);



public:

};

#endif //PROJECT1_SPARTYGNOME_H
