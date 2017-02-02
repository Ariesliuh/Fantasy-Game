// dwarf.h
//
// header of dwarf
//
//author: Dongao
//date: 16.11.2016
#ifndef dwarf_h
#define dwarf_h

#include <iostream>
#include <cstdlib>

#include "character.h"
#include "display_management.h"
namespace game {

  //CDwarf
  //This is a class which define dwarf
  //
  //author: Dongao
  //date: 16.11.2016
  class CDwarf: public CCharacter{
  // variables block
  public:
    CDwarf();
    ~CDwarf();
    void specialAbility();// set the speical ability of dwarf
    void description();
  };
}
#endif
