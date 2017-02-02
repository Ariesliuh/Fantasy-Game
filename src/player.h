// player.h
//
// player header
//
// author: Hang
// date: 13.11.2016
#ifndef player_h
#define player_h
#include <limits>
#include <iostream>
#include <cstdlib>

#include "character.h"
#include "map_management.h"

namespace game {
  // enum of orientation
  typedef enum EMOrientation{
    NORTH = 0,
    SOUTH,
    EAST,
    WEST
  } emOrien;

  // CPlayer
  // Extend Player actions.
  //
  // author: Hang
  // data: 15.11.2016
  class CPlayer{

  public:
    // get the instance of CMapManagement.
    static CPlayer* GetInstance(CCharacter* character);
    static CPlayer* GetInstance();

    //==================== function block ====================
    ~CPlayer();
    // set character for player
    void setCharacter(CCharacter* character);
    // get current posistion
    TPosition getPosition() const;
    // get the gold amount of player
    int getGold() const;
    // when player defeat enemy, player will get the gold
    void setGold(int nGold);
    // the moving operation
    void move(EMOrientation orien);
    // the looking operation, look the item and character in current square
    void look();
    // print the character state
    void info();
    // pick up an item
    void pickUpItem();
    // drop an item in a empty square
    void dropItem();
    // attack operation
    void attackEnemy();
    // the special ability of character
    void specialAbility();
    // print the character information
    void printDetials();
    // judge whether the character is dead
    void judgeDead();
    // receive player's input operation and judge whether the operation is right
    void readInput(int weapon,int armour,int shield,int ring,int size);

  private:
    // player's instance. In the game there is only one instance
    static CPlayer* _pInstance;
    // the pointer of CCharacter class
    CCharacter* _pCharacter;
    // the pointer of CMapMangement class
    CMapManagement* _pMapManag;
    // the struct of position
    TPosition _tPos;
    // the amount of gold
    int _nGold;
    CPlayer();
  };
}
#endif
