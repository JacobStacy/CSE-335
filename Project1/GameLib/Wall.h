/**
 * @file Wall.h
 * @author Jacob Stacy
 * Class declaration for the Wall Item
 */

#ifndef PROJECT1_Wall_H
#define PROJECT1_Wall_H

#include "Item.h"

/**
 * Class for the Wall Item
 */
class Wall : public Item {
private:

    /// The underlying item Bitmap for the center pieces
    std::shared_ptr<wxBitmap>mCenterBitmap;

    /// width of the Wall
    double mWidth = 32;

    /// height of the Wall
    double mHeight = 32;

protected:
    /**
     * Gets Wall width to be used with collision
     * @return width of the Wall
     */
    double GetWidth() override { return mWidth; }

    /**
     * Gets Wall height to be used with collision
     * @return height of the Wall
     */
    double GetHeight() override { return mHeight; }

public:

    /// Default constructor (disabled)
    Wall() = delete;

    /// Copy constructor (disabled)
    Wall(const Wall &) = delete;


    Wall(Game* game,
            std::shared_ptr<wxBitmap> bitmap,
            int width,
            int height);

    /// Assignment operator
    void operator=(const Wall &) = delete;

    void Draw(wxGraphicsContext *gc) override;
    /**
     * Accept a visitor
     * @param visitor
     */
    void Accept(ItemVisitor* visitor) override {visitor->VisitWall(this);}

    /**
     * Loads wall as Wall object
     * @param node
     */
    void XmlLoad(wxXmlNode* node) override;
};

#endif //PROJECT1_Wall_H
