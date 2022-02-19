/**
 * @file ZombieDistributor.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CITY_ZOMBIEDISTRIBUTOR_H
#define CITY_ZOMBIEDISTRIBUTOR_H

#include "TileVisitor.h"
#include "TileHive.h"
#include "TileLandscape.h"
#include "TileBuilding.h"
#include <vector>
#include <random>

/**
 * Concrete Visitor that distributes zombies to tiles
 */
class ZombieDistributor : public TileVisitor {
private:
    /// Zombies to distribute
    int* mZombies;

    /// Landscape available to infect
    std::vector<TileLandscape*> mLandscapes;

    /// Random number generator
    std::mt19937 mRandom;

public:

    ZombieDistributor(int* zombies);

    /// Default constructor (disabled)
    ZombieDistributor() = delete;

    /**
     * Does nothing
     * @param hive have nothing is done to
     */
    void VisitHive (TileHive* hive) override {}
    void VisitLandscape (TileLandscape* landscape) override;
    void VisitBuilding (TileBuilding* building) override;

    void DistributeLandscapes();



};

#endif //CITY_ZOMBIEDISTRIBUTOR_H
