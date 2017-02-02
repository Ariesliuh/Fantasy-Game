// item.cpp
//
// This is super class of items
//
// author: Paerhati
// date: 17.11.2016
#include "item.h"

using namespace game;
using namespace std;

// Function: printItemDetails()
//
// Description: print private variables
//
// Return: void
void CItem::printItemDetails(){
  MESSAGE("\nThis square is occupied by %s", _strName.c_str());
  if (_nAttack != 0)
    MESSAGE(" Attack=%d", _nAttack);
  if (_nDefense != 0)
    MESSAGE(" Defense=%d", _nDefense);
  if (_nWeight != 0)
    MESSAGE(" Weight=%d", _nWeight);
  if (_nHealth != 0)
    MESSAGE(" Health=%d", _nHealth);
  if (_nStrength != 0)
    MESSAGE(" Strength=%d", _nStrength);
}

string CItem::getItemName() const{
  return _strName;
}

EMItem CItem::getItemType() const {
  return _emType;
}

int CItem::getAttack() const{
  return _nAttack;
}

int CItem::getDefense() const{
  return _nDefense;
}

int CItem::getWeight() const{
  return _nWeight;
}

int CItem::getHealth() const{
  return _nHealth;
}

int CItem::getStrength() const{
  return _nStrength;
}

// the description of the instance of CItem
void CItem::description(){

}
