/**
 * @file Chicken.cpp
 *
 * @author Jacob R. Stacy
 */

#include <iostream>
#include "Chicken.h"

using namespace std;


/**
 * Obtain a chicken description from the user.
 */
void Chicken::ObtainChickenInformation()
{
    cout << endl;
    cout << "Input information about the chicken" << endl;

    // Obtain the ID. This is easy, since it's just a
    // string.
    cout << "Id: ";
    cin >> mId;
}

/*
 * Returns that the chicken is a defender.
 * */
bool Chicken::IsDefender()
{
    return true;
}

/**
 * Display the chicken.
 */
void Chicken::DisplayAnimal()
{
    cout << "Chicken: " << mId << endl;
}