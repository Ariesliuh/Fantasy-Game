// chars_management.cpp
//
// This is file defines a class which manages all characters.
//
// author: Hang
// date: 13.11.2016
#include "chars_management.h"

using namespace game;
using namespace std;

CCharacterManagement* CCharacterManagement::_pInstance;

CCharacterManagement::CCharacterManagement(){}
CCharacterManagement::~CCharacterManagement(){}

// Function: GetInstance
//
// Description: using singleton, to get one CCharacterManagement instance.
//          If there is a instance, do nothing.
//
// Return: CCharacterManagement - the executable only one instance
CCharacterManagement* CCharacterManagement::GetInstance() {
  if(_pInstance == NULL)
    _pInstance = new CCharacterManagement();
  return _pInstance;
}

// Function: createCharacter
//
// Description: using factory to create different races character.
//
// Parameter: 1.race - this is a enum variable, tell the function which race
//                   need to create
//
// Return: CCharacter - return created character.
CCharacter* CCharacterManagement::createCharacter(EMCharacterRace race){
  CCharacter* cc;
  // get datetime instance
  CDateTime* pDateTime = CDateTime::GetInstance();
  switch(race){
  case HUMAN:
    cc = new CHuman();
    break;
  case ELF:
    cc = new CElf();
    break;
  case DWARF:
    cc = new CDwarf();
    break;
  case HOBBIT:
    cc = new CHobbit();
    break;
  case ORC:
    cc = new COrc();
    // register observer for orc, when datetime changed the subject will notify orc
    pDateTime->registerObserver(cc);
    break;
  default:
    break;
  }
  return cc;
}

void CCharacterManagement::description(){
  MESSAGE("\nThis is the CharacterManagement class");
}
