/**
 * @file FishMosquito.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef AQUARIUM_FISHMOSQUITO_H
#define AQUARIUM_FISHMOSQUITO_H

#include "Item.h"

class FishMosquito : public Item {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mFishImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mFishBitmap;

    /// The last fish the fish has mated with
    std::shared_ptr<Item> mEx;

public:
    /// Default constructor (disabled)
    FishMosquito() = delete;

    /// Copy constructor (disabled)
    FishMosquito(const FishMosquito &) = delete;

    /// Assignment operator
    void operator=(const FishMosquito &) = delete;

    FishMosquito(Aquarium* aquarium);

    void FishMosquito::Draw(wxDC* dc) override;

    bool HitTest(int x, int y) override;

//    void SetLocation(double x, double y) override;

    bool Breed(std::shared_ptr<Item> mate) override;
};

#endif //AQUARIUM_FISHMOSQUITO_H