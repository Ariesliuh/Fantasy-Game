// weapon.cpp
//
// This is weapons class
//
// author: Paerhati
// date: 17.11.2016
#include "weapon.h"

using namespace game;
using namespace std;

CWeapon::CWeapon(EMWeapon emWeapon){
  // initialize properties
  switch (emWeapon){
  case SWORD:
    _strName = "Sword";
    _nAttack = 10;
    _nWeight = 10;
    break;
  case DAGGER:
    _strName = "Dagger";
    _nAttack = 5;
    _nWeight = 5;
  }
  _nDefense = 0;
  _nHealth = 0;
  _nStrength = 0;
  _emType = WEAPON;
}

CWeapon::~CWeapon(){}

void CWeapon::description(){}

// Function: printInfo
//
// Description: print weapon info.
//
// Return: void.
void CWeapon::printInfo(){
  MESSAGE("\n %s: Weight: %d, Attack: +%d", _strName.c_str(), _nWeight, _nAttack);
}
