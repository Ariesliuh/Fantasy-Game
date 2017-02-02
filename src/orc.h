// orc.h
//
// header of orc
//
//author: Dongao
//date: 16.11.2016
#ifndef orc_h
#define orc_h

#include <iostream>
#include <cstdlib>

#include "character.h"
#include "datetime.h"
#include "display_management.h"

namespace game {

  //COrc
  //This is a class which define orc
  //
  //author: Dongao
  //date: 16.11.2016
  class COrc: public CCharacter{
  // variables block
  public:
    COrc();
    virtual ~COrc();
    void update(const std::string &msg);// update the orc state
    void specialAbility();// set the orc special ability
    void description();
  private:
    void switchAbility(EMDateTime emDataTime);// switch the special ability
  };
}
#endif
