// armour.h
//
// armour header
//
// author: Paerhati
// date: 18.11.2016
#ifndef armour_h
#define armour_h

#include <iostream>
#include <cstdlib>

#include "item.h"
namespace game {
  enum EMArmour {
    PLATE = 0,
    LEATHER
  };

  // CArmour
  // CArmour class includes Plate Armour and Leather Armour
  //
  // author: Paerhati
  // data: 18.11.2016
  class CArmour: public CItem {
  public:
    CArmour(EMArmour emArmour);
    ~CArmour();
    void description();
    void printInfo();
  };
}
#endif
