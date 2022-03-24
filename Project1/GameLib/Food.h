/**
 * @file Food.h
 * @author Kurt LaBlanc
 * Defines Food class
 */

#ifndef PROJECT1_FOOD_H
#define PROJECT1_FOOD_H


#include "Item.h"

/**
 * Creates food class inherited from Item
 */
class Food : public Item{
private:
    /// Vector containing position of food items
    Vector mV;

    /// True if food is come into contact; false otherwise
    bool mText = false;
public:
    ///Default constructor
    Food() = delete;

    ///Copy constructor
    Food(const Food &) = delete;


    Food(Game* game, std::shared_ptr<wxBitmap> bitmap);

///Assignment operator
    void operator = (const Food &) = delete;

   // wxXmlNode* XmlSave(wxXmlNode* node) override;

    bool CollisionTest(Item *item) override;

    void Update(double elapsed) override;

    void Draw(wxGraphicsContext* gc) override;

};



#endif //PROJECT1_FOOD_H
