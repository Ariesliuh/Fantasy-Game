// armour.cpp
//
// This is armours class
//
// author: Paerhati
// date: 18.11.2016
#include "armour.h"

using namespace game;
using namespace std;

CArmour::CArmour(EMArmour emArmour){
  // initialize properties
  switch (emArmour){
  case PLATE:
    _strName = "Plate";
    _nAttack = -5;
    _nDefense = 10;
    _nWeight = 40;
    break;
  case LEATHER:
    _strName = "Leather";
    _nAttack = 0;
    _nDefense = 5;
    _nWeight = 20;
  }
  _nHealth = 0;
  _nStrength = 0;
  _emType = ARMOUR;
}

CArmour::~CArmour(){}

void CArmour::description(){}

// Function: printInfo
//
// Description: print armour info
//
// Return: void
void CArmour::printInfo(){
  MESSAGE("\n %s: Weight: %d, Attack: %d, Defence +%d ", _strName.c_str(), _nWeight, _nAttack, _nDefense);
}
