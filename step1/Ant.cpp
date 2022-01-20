/**
 * @file Ant.cpp
 * @author Jacob R. Stacy
 */

#include <iostream>
#include <cctype>
#include "Ant.h"

using namespace std;


/**
 * Obtain information from the user about this ant.
 *
 * Asks the user for the information that describes a ant.
 */
void Ant::ObtainAntInformation()
{
    cout << endl;
    cout << "Input information about the ant" << endl;

    // Obtain the code. This is easy, since it's just a
    // string.
    bool valid = false;
    while (!valid)
    {
        cout << "Code: ";
        cin >> mCode;
        if (!cin){
            // We have an error. Clear the input and try again
            cin.clear();
            cin.ignore();
            continue;
        }

        if (mCode.length() == 3){
            valid = true;
            for (auto c : mCode)
            {
                if (!isupper(c)) {
                    valid = false;
                }
            }
        }

        if (!valid) {
            cout << "Code for Ant must be 3 capital letters, ex: XXX" << endl;
        }

    }


    // Obtain the type using a menu. We have a loop so
    // we can handle errors.
    valid = false;
    while (!valid)
    {
        cout << "1: Worker Ant" << endl;
        cout << "2: Soldier Ant" << endl;
        cout << "3: Drone" << endl;
        cout << "4: Queen" << endl;
        cout << "Enter selection and return: ";
        int option;
        cin >> option;
        if (!cin)
        {
            // We have an error. Clear the input and try again
            cin.clear();
            cin.ignore();
            continue;
        }

        // Sets the type of the ant.
        switch (option)
        {
        case 1:
            mType = Type::Worker;
            valid = true;
            break;

        case 2:
            mType = Type::Soldier;
            valid = true;
            break;

        case 3:
            mType = Type::Drone;
            valid = true;
            break;

        case 4:
            mType = Type::Queen;
            valid = true;
            break;
        }

    }


    valid = false;
    while (!valid)
    {
        cout << "Enter radiation level of this ant in millisieverts per hour: ";

        cin.clear();
        cin.ignore();
        cin >> mRadiation;
        if (cin)
        {
            valid = true;
        }
    }
}

/*
 * Returns if the ant is a defender.
 * */
bool Ant::IsDefender()
{
    if (mType == Type::Soldier) {
        return true;
    } else {
        return false;
    }
}


/**
 * Display information about this ant.
 */
void Ant::DisplayAnimal()
{
    cout << "Ant " << mCode << " is a ";
    switch (mType)
    {
    case Type::Worker:
        cout << "Worker Ant ";
        break;

    case Type::Soldier:
        cout << "Soldier Ant ";
        break;

    case Type::Drone:
        cout << "Drone ";
        break;

    case Type::Queen:
        cout << "Queen ";
        break;
    }
    cout << "with a radiation level of " << mRadiation << " mSv/hr" << endl;
}