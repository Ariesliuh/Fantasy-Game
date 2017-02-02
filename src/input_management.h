// input_management.h
//
// header of input_management.
//
// author: Dongao
// date: 19.11.2016

#ifndef input_management_h
#define input_management_h

#include <iostream>
#include <cstdlib>

#include "display_management.h"
#include "datetime.h"
#include "player.h"

namespace game{

  // CInputManagement
  // This is a class manages input
  //
  // author: Dongao
  // data: 19.11.2016
  class CInputManagement{
  public:
    ~CInputManagement();
    // this is singleton function
    static CInputManagement* GetInstance();
    // count the number of command
    void timeManagement();
    // all users input operation will be received in this function
    //    then notify other operation.
    void inputOperations();
    // move north
    void upOperation();
    // move south
    void downOperation();
    // move weat
    void leftOperation();
    // move east
    void rightOperation();
    // pick up an item
    void pickOperation();
    // exit the game
    void exitOperation();
    // drop an item on a square
    void dropOperation();
    // attack other character
    void attackOperation();
    // check the square info
    void lookOperation();
    // check player info
    void inventoryOperation();

  private:
    CInputManagement();
    // the instance of this class
    static CInputManagement* _pInstance;

    CPlayer* _pPlayer;
    CDateTime* _pDateTime;
  };
}
#endif
