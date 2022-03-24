/**
 * @file ItemVisitor.h
 * @author Matt Wright, Kurt LaBlanc
 * Defines ItemVisitor Class
 */

#ifndef PROJECT1_ITEMVISITOR_H
#define PROJECT1_ITEMVISITOR_H

// Forward references for all items
class SpartyGnome;
class Platform;
class Money;
class Villain;
class Wall;
class ItemBackground;
class Stanley;

/**Item Visitor base class*/
class ItemVisitor {
private:

public:
    /**
     * Visit a gnome object
     * @param gnome
     */
    virtual void VisitGnome(SpartyGnome* gnome) {}

    /**
     * Visit money object
     * @param money
     */
    virtual void VisitMoney(Money* money) {}

    /**
     * Visit platform object
     * @param platform
     */
    virtual void VisitPlatform(Platform* platform) {}

    /**
     * Visit villain object
     * @param villain
     */
    virtual void VisitVillain(Villain* villain) {}

    /**
     * Visit wall object
     * @param wall
     */
    virtual void VisitWall(Wall* wall) {}

    /**
     * Visit background
     * @param back
     */
    virtual void VisitItemBackground(ItemBackground* back) {}

    /**
     * Visit stanley
     * @param stanley
     */
    virtual void VisitStanley(Stanley* stanley) {}

};

#endif //PROJECT1_ITEMVISITOR_H
