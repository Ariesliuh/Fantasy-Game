// chars_management.h
//
// header of chars_management
//
// author: Hang
// date: 13.11.2016
#ifndef chars_management_h
#define chars_management_h

#include <iostream>
#include <cstdlib>

#include "character.h"
#include "datetime.h"
#include "human.h"
#include "elf.h"
#include "hobbit.h"
#include "dwarf.h"
#include "orc.h"

namespace game {

  // CCharacterManagement
  // This is a class manages characters
  //
  // author: Hang
  // data: 13.11.2016
  class CCharacterManagement{
  public:
    ~CCharacterManagement();
    static CCharacterManagement* GetInstance();// get the instance
    CCharacter* createCharacter(EMCharacterRace race);
    void description();

  private:
    CCharacterManagement();
    static CCharacterManagement* _pInstance;
  };

}

#endif
