// hobbit.cpp
//
// This is file defines a class which defines Hobbit class.
//
// author: Dongao
// date: 16.11.2016
#include "hobbit.h"

using namespace game;
using namespace std;

// construct function
CHobbit::CHobbit(){
  // initialize properties
  _strRaceName = "Hobbit";
  _nAttack = 25;
  _fAttackChance = 1.0/3.0;
  _nDefense = 20;
  _fDefenseChance= 2.0/3.0;
  _nHealth = 70;
  _nStrength = 85;

  _pWeapon = NULL;
  _pShield = NULL;
  _pArmour = NULL;
  // _vecRing = NULL;
}

// deconstruct function
CHobbit::~CHobbit(){
  // clear the vector
  _vecRing.clear();
  // release the capacity of vector
  vector <CRing>().swap(_vecRing);
}

// Function: specialAbility
//
// Description: set special ability of hobbit, if the hobbit defense successful,
//                this function will be called.
//
// Return: void
void CHobbit::specialAbility(){
  Debug("\nthis is a hobbit specialAbility");
  _nSufferHurt = rand()%6;
  _fSufferAttackRate = 0;
}

void CHobbit::description(){
  MESSAGE("\nFor the horde!");
}
