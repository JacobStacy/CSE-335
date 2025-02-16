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
#include <random>
#include "Item.h"

/**
 * Class for our Aquarium
 */
class Aquarium {
private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<Item>> mItems;

    /// XmlItem
    void XmlItem(wxXmlNode* node);

    /// Random number generator
    std::mt19937 mRandom;

public:
    void OnDraw(wxDC *dc);
    Aquarium();
    void Add(std::shared_ptr<Item> item);

    std::shared_ptr<Item> HitTest(int x, int y);

    std::shared_ptr<Item> GetClosestTo(std::shared_ptr<Item> item);

    void Top(std::shared_ptr<Item> item);

    void Save(const wxString& filename);

    void Load(const wxString& filename);

    void Clear();

    void Update(double elapsed);

    /**
     * Get the random number generator
     * @return Pointer to the random number generator
     */
    std::mt19937 &GetRandom() {return mRandom;}

    /**
     * Get the width of the aquarium
     * @return Aquarium width in pixels
     */
    int GetWidth() const { return mBackground->GetWidth(); }

    /**
     * Get the height of the aquarium
     * @return Aquarium height in pixels
     */
    int GetHeight() const { return mBackground->GetHeight(); }
};

#endif //AQUARIUM_AQUARIUM_H
