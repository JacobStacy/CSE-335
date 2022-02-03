/**
 * @file Aquarium.h
 * @author Jacob Stacy
 *
 * Declaration of the Aquarium class.
 *
 */

#ifndef AQUARIUM_AQUARIUM_H
#define AQUARIUM_AQUARIUM_H

#include <memory>
#include "Item.h"

class Aquarium {
private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<Item>> mItems;
public:
    void OnDraw(wxDC *dc);
    Aquarium();
    void Add(std::shared_ptr<Item> item);

    std::shared_ptr<Item> HitTest(int x, int y);

    std::shared_ptr<Item> GetClosestTo(std::shared_ptr<Item> item);

    void Top(std::shared_ptr<Item> item);
};

#endif //AQUARIUM_AQUARIUM_H
