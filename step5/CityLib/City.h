/**
 * @file City.h
 *
 * @author Charles B. Owen
 *
 *  Class that implements a simple city with tiles we can manipulate
 */

#pragma once

#include <memory>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include <random>

#include "Tile.h"

class CityReport;

/**
 *  Implements a simple city with tiles we can manipulate
 */
class City
{
private:
    void XmlTile(wxXmlNode *node);
    void BuildAdjacencies();

    /// All of the tiles that make up our city
    std::vector<std::shared_ptr<Tile> > mTiles;

    /// Adjacency lookup support
    std::map<std::pair<int, int>, std::shared_ptr<Tile> > mAdjacency;

    /// Directory containing the system images
    std::wstring mImagesDirectory;

    /// Do we display the population?
    bool mViewPopulation = false;

    /// Random number generator
    std::mt19937 mRand;

public:
    City();

    /**
     * Destructor
    */
    virtual ~City() = default;

    /**
     * Get the random number generator
     * @return Random number generator
     */
    std::mt19937* GetRand() {return &mRand;}

    /// The spacing between grid locations
    static const int GridSpacing = 32;

    /**
     * Get the directory the images are stored in
     * @return Images directory path
     */
    const std::wstring &GetImagesDirectory() const { return mImagesDirectory; }

    void SetImagesDirectory(const std::wstring &dir);

    void Add(std::shared_ptr<Tile> item);
    std::shared_ptr<Tile> HitTest(int x, int y);
    void MoveToFront(std::shared_ptr<Tile> item);
    void DeleteItem(std::shared_ptr<Tile> item);

    void OnDraw(wxDC *graphics);

    void Save(const wxString &filename);
    void Load(const wxString &filename);
    void Clear();

    void Update(double elapsed);
    void SortTiles();

    std::shared_ptr<Tile> GetAdjacent(std::shared_ptr<Tile> tile, int dx, int dy);
    std::shared_ptr<Tile> GetAdjacent(Tile *tile, int dx, int dy);

    std::shared_ptr<CityReport> GenerateCityReport();

    /**
     * Is the option to view the population enabled?
     * @return True if enabled
     */
    bool IsViewPopulation() const { return mViewPopulation; }

    /**
     * Flip the true/false status of population viewing
     */
    void FlipViewPopulation() { mViewPopulation = !mViewPopulation; }
};

