// shield.cpp
//
// This is shield class
//
// author: Paerhati
// date: 18.11.2016
#include "shield.h"

using namespace game;
using namespace std;

CShield::CShield(EMShield emShield){
  // initialize properties
  switch (emShield){
  case LARGE_SHIELD:
    _strName = "Large Shield";
    _nAttack = -5;
    _nDefense = 10;
    _nWeight = 30;
    break;
  case SMALL_SHIELD:
    _strName = "Small Shield";
    _nAttack = 0;
    _nDefense = 5;
    _nWeight = 10;
  }
  _nHealth = 0;
  _nStrength = 0;
  _emType = SHIELD;
}

CShield::~CShield(){}

void CShield::description(){}

// Function: printInfo
//
// Description: print shield info
//
// Return: void
void CShield::printInfo(){
  MESSAGE("\n %s: Weight: %d, Attack: %d, Defence: +%d", _strName.c_str(), _nWeight, _nAttack, _nDefense);
}
