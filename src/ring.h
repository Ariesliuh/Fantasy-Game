// ring.h
//
// ring header
//
// author: Paerhati
// date: 18.11.2016
#ifndef ring_h
#define ring_h

#include <iostream>
#include <cstdlib>

#include "item.h"
namespace game {
  enum EMRing {
    RING_LIFE = 0,
    RING_STRENGTH
  };

  // CRing
  // CRing class includes Ring Life and Ring Strength
  //
  // author: Paerhati
  // data: 18.11.2016
  class CRing: public CItem {
  public:
    CRing(EMRing emRing);
    ~CRing();
    void description();
    void printInfo();
  };
}
#endif
