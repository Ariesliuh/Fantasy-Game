// elf.h
//
// header of elf
//
// author: Dongao
// date: 13.11.2016
#ifndef elf_h
#define elf_h

#include <iostream>
#include <cstdlib>

#include "character.h"

namespace game {

  // CElf
  // This is a class which define elf
  //
  // author: Dongao
  // data: 13.11.2016
  class CElf: public CCharacter{
  // variables block
  public:
    CElf();
    ~CElf();
    void specialAbility();// set the elf special ability
    void description();
  };
}
#endif
