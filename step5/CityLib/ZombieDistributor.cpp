/**
 * @file ZombieDistributor.cpp
 * @author Jacob Stacy
 */

#include "pch.h"
#include "ZombieDistributor.h"


/**
 * Constructor for ZombieDistributor
 * @param zombies zombies that are being distributed
 */
ZombieDistributor::ZombieDistributor(int* zombies)
{
    mZombies = zombies;

    // Seed the random number generator
    std::random_device rd;
    mRandom.seed(rd());
}


/**
 * Adds landscape to mLandscapes
 * @param landscape the landscape added
 */
void ZombieDistributor::VisitLandscape(TileLandscape* landscape)
{
    mLandscapes.push_back(landscape);
}

/**
 * Infects building if enough zombies
 * @param building building infected
 */
void ZombieDistributor::VisitBuilding(TileBuilding* building)
{
    if (*mZombies > 0)
    {
        if (building->Infect())
        {
            (*mZombies)--;
        }
    }
}

/**
 * Distributes remaining zombies to landscapes
 */
void ZombieDistributor::DistributeLandscapes()
{
    if (*mZombies > 0)
    {
        if (static_cast<int>(mLandscapes.size()) != 0)
        {
            std::uniform_int_distribution<> distribution(0, static_cast<int>(mLandscapes.size() - 1));
            int index = distribution(mRandom);
            mLandscapes[index]->Infect();
            mLandscapes[index]->ReceiveZombies(*mZombies);
            *mZombies = 0;
        }
    }
}