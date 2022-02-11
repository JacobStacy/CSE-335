#include <pch.h>
#include "gtest/gtest.h"
#include <Aquarium.h>
#include <FishBeta.h>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>
#include <FishNemo.h>
#include <FishCarp.h>
#include <DecorCastle.h>

using namespace std;

class AquariumTest : public ::testing::Test {
protected:
    /**
    * Create a path to a place to put temporary files
    */
    wxString TempPath()
    {
        // Create a temporary filename we can use
        auto path = wxFileName::GetTempDir()+L"/aquarium";
        if (!wxFileName::DirExists(path)) {
            wxFileName::Mkdir(path);
        }

        return path;
    }

    /**
    *  Populate an aquarium with three Beta fish
    */
    void PopulateThreeBetas(Aquarium* aquarium)
    {
        auto fish1 = make_shared<FishBeta>(aquarium);
        aquarium->Add(fish1);
        fish1->SetLocation(100, 200);
        fish1->SetSpeedX(100);
        fish1->SetSpeedY(100);

        auto fish2 = make_shared<FishBeta>(aquarium);
        aquarium->Add(fish2);
        fish2->SetLocation(400, 400);
        fish2->SetSpeedX(110);
        fish2->SetSpeedY(110);

        auto fish3 = make_shared<FishBeta>(aquarium);
        aquarium->Add(fish3);
        fish3->SetLocation(600, 100);
        fish3->SetSpeedX(111.0);
        fish3->SetSpeedY(111.0);
    }

    void TestThreeBetas(wxString filename)
    {
        cout << "Temp file: " << filename << endl;

        auto xml = ReadFile(filename);
        cout << xml << endl;

        // Ensure three items
        ASSERT_TRUE(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

        // Ensure the positions are correct
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\" speedX=\"100\" speedY=\"100\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\" speedX=\"110\" speedY=\"110\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\" speedX=\"111\" speedY=\"111\"")));

        // Ensure the types are correct
        ASSERT_TRUE(regex_search(xml,
                wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"beta\"/><item.* type=\"beta\"/></aqua>")));
    }

    /**
    *  Populate an aquarium with three Beta fish
    */
    void PopulateAllTypes(Aquarium* aquarium)
    {
        auto item1 = make_shared<FishBeta>(aquarium);
        aquarium->Add(item1);
        item1->SetSpeedX(100);
        item1->SetSpeedY(100);
        item1->SetLocation(100, 200);

        auto item2 = make_shared<FishNemo>(aquarium);
        aquarium->Add(item2);
        item2->SetSpeedX(110);
        item2->SetSpeedY(110);
        item2->SetLocation(400, 400);

        auto item3 = make_shared<FishCarp>(aquarium);
        aquarium->Add(item3);
        item3->SetSpeedX(111);
        item3->SetSpeedY(111);
        item3->SetLocation(600, 100);

        auto item4 = make_shared<DecorCastle>(aquarium);
        aquarium->Add(item4);
        item4->SetLocation(500, 100);
    }

    void TestAllTypes(wxString filename)
    {
        cout << "Temp file: " << filename << endl;

        auto xml = ReadFile(filename);
        cout << xml << endl;

        // Ensure four items
        ASSERT_TRUE(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*<item.*</aqua>")));

        // Ensure the positions are correct
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\" speedX=\"100\" speedY=\"100\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\" speedX=\"110\" speedY=\"110\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\" speedX=\"111\" speedY=\"111\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"500\" y=\"100\"")));

        // Ensure the types are correct
        ASSERT_TRUE(regex_search(xml,
                wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"nemo\"/><item.* type=\"carp\"/><item.* type=\"castle\"/></aqua>")));
    }

    /**
    * Read a file into a wstring and return it.
    * @param filename Name of the file to read
    * @return File contents
    */
    wstring ReadFile(const wxString& filename)
    {
        ifstream t(filename.ToStdString());
        wstring str((istreambuf_iterator<char>(t)),
                istreambuf_iterator<char>());

        return str;
    }

    /**
     * Test to ensure an aquarium .aqua file is empty
     * @param filename Filename that is being checked
     */
    void TestEmpty(wxString filename)
    {
        cout << "Temp file: " << filename << endl;

        auto xml = ReadFile(filename);
        cout << xml << endl;

        ASSERT_TRUE(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<aqua/>")));
    }
};

TEST_F(AquariumTest, Construct)
{
    Aquarium aquarium;
}

TEST_F(AquariumTest, HitTest)
{
    Aquarium aquarium;

    ASSERT_EQ(aquarium.HitTest(100, 200), nullptr) <<
                                                   L"Testing empty aquarium";

    shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
    aquarium.Add(fish1);
    fish1->SetLocation(100, 200);

    ASSERT_TRUE(aquarium.HitTest(100, 200)==fish1) <<
                                                   L"Testing fish at 100, 200";

    shared_ptr<FishBeta> fish2 = make_shared<FishBeta>(&aquarium);
    aquarium.Add(fish2);
    fish2->SetLocation(100, 200);

    ASSERT_TRUE(aquarium.HitTest(100, 200)==fish2) << L"Testing two fish on top of each other";

    ASSERT_TRUE(aquarium.HitTest(100, 20000)==nullptr) << L"Testing hitting where there is no fish";
}

TEST_F(AquariumTest, Save)
{
    // Create a path to temporary files
    auto path = TempPath();

    // Create an aquarium
    Aquarium aquarium;

    //
    // First test, saving an empty aquarium
    //
    auto file1 = path+L"/test1.aqua";
    aquarium.Save(file1);

    TestEmpty(file1);

    //
    // Now populate the aquarium
    //

    PopulateThreeBetas(&aquarium);

    auto file2 = path+L"/test2.aqua";
    aquarium.Save(file2);

    TestThreeBetas(file2);
}

TEST_F(AquariumTest, Clear)
{
    // Create a path to temporary files
    auto path = TempPath();

    // Create an aquarium
    Aquarium aquarium;

    //
    // First test, saving an empty aquarium
    //
    auto file1 = path+L"/test1.aqua";
    aquarium.Save(file1);

    TestEmpty(file1);

    //
    // Now populate the aquarium
    //
    PopulateThreeBetas(&aquarium);

    auto file2 = path+L"/test2.aqua";
    aquarium.Save(file2);

    TestThreeBetas(file2);

    //
    // Clear the aquarium
    //
    aquarium.Clear();
    aquarium.Save(file2);
    TestEmpty(file2);
}

TEST_F(AquariumTest, Load) {
    // Create a path to temporary files
    auto path = TempPath();

    // Create an aquarium
    Aquarium aquarium;
    Aquarium aquarium2;

    //
    // First test, saving an empty aquarium
    //
    auto file1 = path + L"/test1.aqua";
    aquarium.Save(file1);

    TestEmpty(file1);

    aquarium2.Load(file1);
    aquarium2.Save(file1);
    TestEmpty(file1);

    //
    // Now populate the aquarium
    //

    PopulateThreeBetas(&aquarium);

    auto file2 = path + L"/test2.aqua";
    aquarium.Save(file2);

    TestThreeBetas(file2);

    aquarium2.Load(file2);
    aquarium2.Save(file2);
    TestThreeBetas(file2);

    //
    // Test all types
    //
    Aquarium aquarium3;
    PopulateAllTypes(&aquarium3);

    auto file3 = path + L"/test3.aqua";
    aquarium3.Save(file3);

    TestAllTypes(file3);

    aquarium2.Load(file3);
    aquarium2.Save(file3);
    TestAllTypes(file3);
}

