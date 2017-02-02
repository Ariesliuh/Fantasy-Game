// hobbit.h
//
// header of hobbit
//
//author: Dongao
//date: 16.11.2016
#ifndef hobbit_h
#define hobbit_h

#include <iostream>
#include <cstdlib>

#include "character.h"
#include "display_management.h"

namespace game {

  //CHobbit
  //This is a class which define hobbit
  //
  //author: Dongao
  //date: 16.11.2016
  class CHobbit: public CCharacter{
    // variables block
  public:
    CHobbit();
    ~CHobbit();
    void specialAbility();// set the hobbit special ability
    void description();
  };
}
#endif
