// item.h
//
// item header
//
// author: Paerhati
// date: 17.11.2016
#ifndef item_h
#define item_h

#include <iostream>
#include <cstdlib>

#include "display_management.h"

namespace game {
  // define kinds of item
  typedef enum EMItem {
    WEAPON = 0,
    ARMOUR,
    SHIELD,
    RING
  } emItem;
  // CItem
  // CItem is a super class of Weapon, Armour, Shield and Ring
  //
  // author: Paerhati
  // data: 17.11.2016
  class CItem{
  public:
    void printItemDetails();
    std::string getItemName() const;
    EMItem getItemType() const;
    int getAttack() const;
    int getDefense() const;
    int getWeight() const;
    int getHealth() const;
    int getStrength() const;
    void description();

  protected:
    // item name
    std::string _strName;
    // kinds of items.
    EMItem _emType;
    int _nAttack;
    int _nDefense;
    int _nWeight;
    int _nHealth;
    int _nStrength;
  };
}
#endif
