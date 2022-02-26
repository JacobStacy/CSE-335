/**
 * @file SpartyGnome.cpp
 * @author matty
 */

#include "pch.h"
#include "SpartyGnome.h"
#include "Game.h"
#include <string>

using namespace std;

const wstring SpartyGnomeNeutral = L"images/gnome.png";

SpartyGnome::SpartyGnome(Game* game) : Item(game, SpartyGnomeNeutral)
{
}

