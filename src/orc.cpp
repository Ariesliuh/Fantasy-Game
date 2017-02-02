// orc.cpp
//
// This is file defines a class which defines Orc class.
//
// author: Dongao
// date: 16.11.2016
#include "orc.h"

using namespace game;
using namespace std;

// construct function
COrc::COrc(){
  // initialize properties
  _strRaceName = "Orc";
  _nAttack = 25;
  _fAttackChance = 1.0/4.0;
  _nDefense = 10;
  _fDefenseChance= 1.0/4.0;
  _nHealth = 50;
  _nStrength = 130;

  _pWeapon = NULL;
  _pShield = NULL;
  _pArmour = NULL;
  // _vecRing = NULL;
}

// deconstruct function
COrc::~COrc(){
  // clear the vector
  _vecRing.clear();
  // release the capacity
  vector <CRing>().swap(_vecRing);
}

// Function: switchAbility
//
// Description: orc has two kinds of state, night state and day state
//                this function is change the orc state when the time change
//
// Parameter: 1.emDataTime : current time 'DAY' or 'NIGHT'
//
// Return: void
void COrc::switchAbility(EMDateTime emDataTime){
  if (emDataTime == DAY) {
    _nAttack = 25;
    _fAttackChance = 1.0/4.0;
    _nDefense = 10;
    _fDefenseChance= 1.0/4.0;
  }else {
    _nAttack = 45;
    _fAttackChance = 1.0;
    _nDefense = 25;
    _fDefenseChance= 1.0/2.0;
  }
}

// Function: update
//
// Description: call the switchAbility function to update the state of orc
//
// Parameter: 1.&msg : current time 'DAY' or 'NIGHT'
//
// Return: void
void COrc::update(const std::string &msg){
  if (msg == "NIGHT") {
    switchAbility(NIGHT);
  }
  if (msg == "DAY") {
    switchAbility(DAY);
  }
}

// Function: specialAbility
//
// Description: set special ability of orc, if the orc defense successful,
//                this function will be called.
//
// Return: void
void COrc::specialAbility(){
  Debug("\nthis is a orc specialAbility");
  CDateTime* pDataTime = CDateTime::GetInstance();
  if (pDataTime->getTime() == DAY)
    _fSufferAttackRate = 0.25; // orc will suffer 1/4 hurt in day time.
  else
    ++_nHealth;
}

void COrc::description(){
  MESSAGE("\nFor the horde!");
}
