/**
 * @file FishNemo.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef AQUARIUM_FISHNEMO_H
#define AQUARIUM_FISHNEMO_H

#include "Item.h"

class FishNemo : public Item {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mFishImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mFishBitmap;

public:
    /// Default constructor (disabled)
    FishNemo() = delete;

    /// Copy constructor (disabled)
    FishNemo(const FishNemo &) = delete;

    /// Assignment operator
    void operator=(const FishNemo &) = delete;

    FishNemo(Aquarium* aquarium);

    void FishNemo::Draw(wxDC* dc) override;

    bool HitTest(int x, int y) override;

    void Spawn(Aquarium*) override;
};

#endif //AQUARIUM_FISHNEMO_H