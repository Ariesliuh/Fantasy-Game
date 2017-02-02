// item_management.h
//
// item_management header
//
// author: Hang Liu
// date: 19.11.2016
#ifndef item_management_h
#define item_management_h

#include <iostream>
#include <cstdlib>

#include "item.h"
#include "weapon.h"
#include "armour.h"
#include "shield.h"
#include "ring.h"

namespace game {

  // CItemManagement
  // manage the items for map, this is a factory class for items
  //
  // author: Hang Liu
  // data: 19.11.2016
  class CItemManagement{
  public:
    ~CItemManagement();
    // get the instance of the CItemManagement
    static CItemManagement* GetInstance();
    // factory function generate the item
    CItem* createItem(EMItem emItem, int detail);
    void description();
  private:
    CItemManagement();
    // the instance of CItemManagement
    static CItemManagement* _pInstance;
  };
}
#endif
