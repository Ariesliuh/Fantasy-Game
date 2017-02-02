// dwarf.cpp
//
// This is file defines a class which defines Dwarf class.
//
// author: Dongao
// date: 16.11.2016
#include "dwarf.h"

using namespace game;
using namespace std;

// construct function
CDwarf::CDwarf(){
  // initialize properties
  _strRaceName = "Dwarf";
  _nAttack = 30;
  _fAttackChance = 2.0/3.0;
  _nDefense = 20;
  _fDefenseChance= 2.0/3.0;
  _nHealth = 50;
  _nStrength = 130;

  _pWeapon = NULL;
  _pShield = NULL;
  _pArmour = NULL;
  // _vecRing = NULL;
}

// deconstruct function
CDwarf::~CDwarf(){
  // clear the vector
  _vecRing.clear();
  // release the vector's capacity
  vector <CRing>().swap(_vecRing);
}

// Function: specialAbility
//
// Description: set special ability of dwarf, if the dwarf defense successful,
//                this function will be called.
//
// Return: void
void CDwarf::specialAbility(){
  Debug("\nthis is a dwarf specialAbility");
  _fSufferAttackRate = 0;
}

void CDwarf::description(){
  MESSAGE("\nFor the horde!");
}
