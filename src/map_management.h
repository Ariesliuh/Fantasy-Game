// map_management.h
//
// map_management header
//
// author: Hang
// date: 18.11.2016
#ifndef map_management_h
#define map_management_h

#include <iostream>
#include <cstdlib>
#include <vector>

#include "display_management.h"
#include "item.h"
#include "character.h"
#include "chars_management.h"
#include "item_management.h"

namespace game {
  // re-define unsigned long long
  typedef unsigned long long ULL;

  // every units structure of map
  typedef struct TSquare{
    // 'i'-item, 'c'-enemy, 'e'-empty. If using ui display to user, it can be used directly.
    char chType;
    union UNSquare{
      // an item in the square
      CItem* i;
      // an enemy in the square
      CCharacter* c;
      // empty square, using 'E' express empty
      char* e;
    } uiContent;
  } tSquare;

  // coordination structure x: x-axis, y: y-axis
  typedef struct TPosition {
    ULL x;
    ULL y;
  } tPosition;

  typedef struct TPoint {
    TSquare s;
    TPosition p;
  } tPoint;

  // CMapManagement
  // Map management manages the map actions.
  //    create properties of map.(squares, items, characters)
  //
  // author: Hang Liu
  // data: 18.11.2016
  class CMapManagement{

  public:
    // get the instance of CMapManagement.
    static CMapManagement* GetInstance();

    //==================== function block ====================
    ~CMapManagement();
    // put user's input x, y into _x and _y
    void setMapRange(ULL width = 3, ULL height = 3);
    // get x-axis size of game board
    ULL getWidth() const;
    // get y-axis size of game board
    ULL getHeight() const;
    // get a square with the square's position
    TSquare getSquareValue(TPosition tPos) const;
    // print a square detail with the square's position
    void printSquareValue(TPosition tPos) const;
    // get an item with the square's position
    CItem* getSquareItem(TPosition tPos) const;
    // get a character with the square's position
    CCharacter* getSquareCharacter(TPosition tPos) const;
    // set a item to a square with the square's position
    void setSquareItem(CItem* pItem, TPosition tPos);
    // remove the content of the square with the square's position
    void clearSquare(TPosition tPos);
    // judge: is there any thing in the square with square's position
    bool isSquareEmpty(TPosition tPos);
    // remove a character from map management
    void removeCharacter(TPosition tPosition);
    // remove an item from map management
    void removeItem(TPosition tPosition);
    // get current number of characters under map management
    int getNumberOfCharacters();
    void description();

  private:
    // num of item/num of empty
    static const float _fItemThreshold;
    // num of character/num of empty
    static const float _fCharacterThreshold;
    // instance of CMapManagement, there is only one in the game
    static CMapManagement* _pInstance;
    ULL _x; // the width of map x-axis
    ULL _y; // the height of map y-axis
    // map container
    std::vector<std::vector <TSquare> > _vecMap;
    // container of storing character point
    std::vector<TPoint> _vecCharacterPoints;
    // container of storing item point
    std::vector<TPoint> _vecItemPoints;
    CCharacterManagement* _pCharManag;
    CItemManagement* _pItemManag;

    //==================== function block ====================
    CMapManagement();
    // create map, call createCharacters and createItems
    void createMap();
    // initialize the map, but no use it, because to increase performence
    void initializeMap();
    // get all num of items, characters, empty
    void getNumbers(float i[], ULL o[]);
    // generate a random position
    TPosition getRandomPosition();
    // call character management to create characters for map
    void createCharacters(ULL number);
    // call item management to create items for map
    void createItems(ULL number);
    // get a random race
    EMCharacterRace getRandomCharacterRace();
    // get a random item type
    EMItem getRandomItem();
    // get random detailed item
    int getRandomDetail();
  };
}
#endif
