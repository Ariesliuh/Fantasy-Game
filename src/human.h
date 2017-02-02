// human.h
//
// header of human
//
// author: Dongao
// date: 13.11.2016
#ifndef human_h
#define human_h

#include <iostream>
#include <cstdlib>

#include "character.h"
#include "display_management.h"

namespace game {

  // CHuman
  // This is a class which define human
  //
  // author: Dongao
  // data: 13.11.2016
  class CHuman: public CCharacter{
  // variables block
  public:
    CHuman();
    ~CHuman();
    void specialAbility();//set the human special ability
    void description();
  };
}
#endif
