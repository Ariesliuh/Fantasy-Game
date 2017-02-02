// weapon.h
//
// weapon header
//
// author: Paerhati
// date: 17.11.2016
#ifndef weapon_h
#define weapon_h

#include <iostream>
#include <cstdlib>

#include "item.h"
namespace game {
  enum EMWeapon {
    SWORD = 0,
    DAGGER
  };

  // CWeapon
  // CWeapon class includes Sword and Dagger
  //
  // author: Paerhati
  // data: 17.11.2016
  class CWeapon: public CItem {
  public:
    CWeapon(EMWeapon emWeapon);
    ~CWeapon();
    void description();
    void printInfo();
  };
}
#endif
