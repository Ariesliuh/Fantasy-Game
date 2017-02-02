// human.cpp
//
// This is file defines a class which defines Human class.
//
// author: Dongao
// date: 13.11.2016
#include "human.h"

using namespace game;
using namespace std;

// construct function
CHuman::CHuman(){
  // initialize properties
  _strRaceName = "Human";
  _nAttack = 30;
  _fAttackChance = 2.0/3.0;
  _nDefense = 20;
  _fDefenseChance = 1.0/2.0;
  _nHealth = 60;
  _nStrength = 100;

  _pWeapon = NULL;
  _pShield = NULL;
  _pArmour = NULL;
  // _vecRing = NULL;
}

// deconstruct function
CHuman::~CHuman(){
  // clear vector
  _vecRing.clear();
  // release vector's capacity
  vector <CRing>().swap(_vecRing);
}

// Function: specialAbility
//
// Description: set special ability of human, if the human defense successful,
//                this function will be called.
//
// Return: void
void CHuman::specialAbility(){
  Debug("\nthis is a human specialAbility");
  _fSufferAttackRate = 0;
}

void CHuman::description(){
  MESSAGE("\nFor the Alliance");
}
