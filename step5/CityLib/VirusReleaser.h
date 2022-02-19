/**
 * @file VirusReleaser.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CITY_VIRUSRELEASER_H
#define CITY_VIRUSRELEASER_H

#include "TileVisitor.h"


/**
 * Concrete Visitor that releases the virus in the hive
 */
class VirusReleaser : public TileVisitor {
private:

public:
    void VisitHive(TileHive *hive) override;

};

#endif //CITY_VIRUSRELEASER_H
