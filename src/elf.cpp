// human.cpp
//
// This is file defines a class which defines Human class.
//
// author: Dongao
// date: 13.11.2016
#include "elf.h"

using namespace game;
using namespace std;

// construct function
CElf::CElf(){
  // initialize properties
  _strRaceName = "Elf";
  _nAttack = 40;
  _fAttackChance = 1.0/1.0;
  _nDefense = 10;
  _fDefenseChance = 1.0/4.0;
  _nHealth = 40;
  _nStrength = 70;

  _pWeapon = NULL;
  _pShield = NULL;
  _pArmour = NULL;
  // _vecRing = NULL;
}

// deconstruct function
CElf::~CElf(){
  // clear vector
  _vecRing.clear();
  // release the capacity of vector
  vector <CRing>().swap(_vecRing);
}

// Function: specialAbility
//
// Description: set special ability of elf, if the elf defense successful,
//                this function will be called.
//
// Return: void
void CElf::specialAbility(){
  _nHealth++;
}

void CElf::description(){
  MESSAGE("\nFor the Alliance");
}
