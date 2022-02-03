/**
 * @file FishCarp.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef AQUARIUM_FISHCARP_H
#define AQUARIUM_FISHCARP_H

#include "Item.h"

class FishCarp : public Item {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mFishImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mFishBitmap;

public:
    /// Default constructor (disabled)
    FishCarp() = delete;

    /// Copy constructor (disabled)
    FishCarp(const FishCarp &) = delete;

    /// Assignment operator
    void operator=(const FishCarp &) = delete;

    FishCarp(Aquarium* aquarium);

    void FishCarp::Draw(wxDC* dc) override;

    bool HitTest(int x, int y) override;

    void Spawn(Aquarium*) override;

};

#endif //AQUARIUM_FISHCARP_H