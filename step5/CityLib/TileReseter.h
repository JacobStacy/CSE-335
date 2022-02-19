/**
 * @file TileReseter.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CITY_TILERESETER_H
#define CITY_TILERESETER_H

#include "TileVisitor.h"
#include "TileHive.h"
#include "TileLandscape.h"
#include "TileBuilding.h"

/**
 * Concrete Visitor that resets the city
 */
class TileReseter : public TileVisitor {
public:
    /**
     * Resets hive
     * @param hive
     */
    void VisitHive (TileHive* hive) override { hive->Reset(); }

    /**
     * Resets landscape
     * @param landscape
     */
    void VisitLandscape (TileLandscape* landscape) override { landscape->Reset(); }

    /**
     * Resets building
     * @param building
     */
    void VisitBuilding (TileBuilding* building) override { building->Reset(); }
};

#endif //CITY_TILERESETER_H
