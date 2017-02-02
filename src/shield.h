// shield.h
//
// shield header
//
// author: Paerhati
// date: 18.11.2016
#ifndef shield_h
#define shield_h

#include <iostream>
#include <cstdlib>

#include "item.h"
namespace game {
  enum EMShield {
    LARGE_SHIELD = 0,
    SMALL_SHIELD
  };

  // CShield
  // CShield class includes Large and Small shield
  //
  // author: Paerhati
  // data: 18.11.2016
  class CShield: public CItem {
  public:
    CShield(EMShield emShield);
    ~CShield();
    void description();
    void printInfo();
  };
}
#endif
