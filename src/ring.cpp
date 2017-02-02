// ring.cpp
//
// This is ring class
//
// author: Paerhati
// date: 18.11.2016
#include "ring.h"

using namespace game;
using namespace std;

CRing::CRing(EMRing emRing){
  // initialize properties
  switch (emRing){
  case RING_LIFE:
    _strName = "Ring Life";
    _nHealth = 10;
    _nStrength = 0;
    break;
  case RING_STRENGTH:
    _strName = "Ring Strength";
    _nHealth = -10;
    _nStrength = 50;
  }
  _nAttack = 0;
  _nDefense = 0;
  _nWeight = 1;
  _emType = RING;
}

CRing::~CRing(){}

void CRing::description(){}

// Function: printInfo
//
// Description: print ring info
//
// Return: void
void CRing::printInfo(){
  MESSAGE("\n %s: Weight: %d, Health: %d, Strength: %d ", _strName.c_str(), _nWeight, _nHealth, _nStrength);
}
