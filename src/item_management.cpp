// item_management.cpp
//
// This is management of items
//
// author: Hang
// date: 19.11.2016
#include "item_management.h"

using namespace game;
using namespace std;

CItemManagement* CItemManagement::_pInstance;

// Function: GetInstance
//
// Description: get the instance using static function. the instance will be create once.
//                other class can get the instance everywhere using this static function.
//
// Return: CItemManagement* - return the instance of this class
CItemManagement* CItemManagement::GetInstance(){
  if(_pInstance == NULL)
    _pInstance = new CItemManagement();
  return _pInstance;
}

// construct function
CItemManagement::CItemManagement(){}

// deconstruct function
CItemManagement::~CItemManagement(){}

// Function: createItem
//
// Description: this is factory function to create different items.
//
// Parameter: 1.emItem - the type of item
//            2.detail - detail level of item.
//
// Return: CItem* - generated item
CItem* CItemManagement::createItem(EMItem emItem, int detail){
  CItem* item;
  switch(emItem){
  case WEAPON:
    item = new CWeapon(EMWeapon(detail));
    break;
  case ARMOUR:
    item = new CArmour(EMArmour(detail));
    break;
  case SHIELD:
    item = new CShield(EMShield(detail));
    break;
  case RING:
    item = new CRing(EMRing(detail));
    break;
  default:
    item = new CItem();
    break;
  }
  return item;
}

void CItemManagement::description(){
  MESSAGE("This is the item management class");
}
