#include <pch.h>
#include "gtest/gtest.h"

#include <City.h>
#include <CityReport.h>
#include <MemberReport.h>

#include <TileLandscape.h>
#include <TileBuilding.h>

using namespace std;

/** Testing stub class, creates a vector from
 * the list. This is done so we can test this
 * before we create the iterator. DO NOT USE
 * THIS CODE to solve the iterator task */
class CityReportStub : public CityReport
{
public:
    CityReportStub(City* city) : CityReport(city) {}

    std::vector<std::shared_ptr<MemberReport>> GetReports()
    {
        // Result list
        std::vector<std::shared_ptr<MemberReport>> list;

        if(!mNoReports)
        {
            unsigned int position = 0;
            while(true) {
                // Grab value at current position
                list.push_back(mReports[position]);

                // If we just grabbed the last position
                // then we are done.
                if(position == mLast)
                {
                    break;
                }

                // Move to the next position in the collection
                position = GrayCode::Increment(position);
            };

        }

        return list;
    }
};

class CityReportTest : public ::testing::Test {
protected:
    static void AddTile(City* city, CityReport* report, std::shared_ptr<Tile> tile)
    {
        city->Add(tile);

        auto memberReport = make_shared<MemberReport>(tile);
        tile->Report(memberReport);
        report->Add(memberReport);
    }

    static void AddLandscape(City* city, CityReport* report, int x, int y)
    {
        auto tile = make_shared<TileLandscape>(city);
        tile->SetLocation(x, y);
        AddTile(city, report, tile);
    }

    static void AddBuilding(City* city, CityReport* report, int x, int y, std::wstring file)
    {
        auto tile = make_shared<TileBuilding>(city);
        tile->SetImage(file);
        tile->SetLocation(x, y);
        AddTile(city, report, tile);
    }
};

TEST_F(CityReportTest, Add)
{
    City city;     // We need a city

    // The report class under test
    CityReportStub report(&city);

    auto results = report.GetReports();
    ASSERT_EQ(0, (int)results.size());

    AddLandscape(&city, &report, 100, 210);

    results = report.GetReports();
    ASSERT_EQ(1, (int)results.size());
    ASSERT_EQ(wstring(L"100, 210: Landscape"), results[0]->Report());

    AddBuilding(&city, &report, 30, 109, L"market.png");

    results = report.GetReports();
    ASSERT_EQ(2, (int)results.size());
    ASSERT_EQ(wstring(L"100, 210: Landscape"), results[0]->Report());
    ASSERT_EQ(wstring(L"30, 109: Building - market.png"), results[1]->Report());

    auto str = results[1]->Report();

    for (int i = 0; i < 100; i++)
    {
        AddLandscape(&city, &report, 100+i, 210);
        AddBuilding(&city, &report, 130, 200+i, L"market.png");
    }

    results = report.GetReports();
    ASSERT_EQ(202, (int)results.size());

    for (int i = 0; i < 100; i++)
    {
        wstringstream str1, str2, str3;
        str1 << 100 + i << ", 210: Landscape";
        str2 << "130, " << 200 + i << ": Building - market.png";

        ASSERT_EQ(str1.str(), results[i * 2 + 2]->Report());
        ASSERT_EQ(str2.str(), results[i * 2 + 3]->Report());
    }

}

