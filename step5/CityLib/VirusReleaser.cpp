/**
 * @file VirusReleaser.cpp
 * @author Jacob Stacy
 */

#include "pch.h"
#include "TileHive.h"
#include "VirusReleaser.h"


/**
 * Releases virus
 * @param hive hive where virus is released
 */
void VirusReleaser::VisitHive(TileHive* hive)
{
    hive->ReleaseTVirus();
}
