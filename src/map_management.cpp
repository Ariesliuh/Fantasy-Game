// map_management.cpp
//
// This is a management class to manage map, like create a map.
//
// author: Hang
// date: 18.11.2016
#include "map_management.h"

using namespace game;
using namespace std;

CMapManagement* CMapManagement::_pInstance;
const float CMapManagement::_fItemThreshold = 0.2f;
const float CMapManagement::_fCharacterThreshold = 0.2f;

// Function: GetInstance
//
// Description: get the instance of CMapManagement.
//
// Return: CMapManagement* - this is the instance of map management
CMapManagement* CMapManagement::GetInstance(){
  if (_pInstance == NULL) {
    _pInstance = new CMapManagement();
  }
  return _pInstance;
}

// construct function
CMapManagement::CMapManagement(){
  _x = 0;
  _y = 0;
}

// Function: setMapRange
//
// Description: put user's input x, y into _x and _y
//    _x, _y are width and height of map
//
// Parameter: 1.width - x-axis size
//            2.height - y-axis size
//
// Return: void
void CMapManagement::setMapRange(ULL width, ULL height){
  if (_x==0 && _y==0) {
    _x = width;
    _y = height;
    // create map
    createMap();
  }
}

// Function: createMap
//
// Description: put user's input x, y into width and height
//
// Parameter: 1.width - x-axis size
//            2.height - y-axis size
//
// Return: void
void CMapManagement::createMap(){
  Debug("\nx:%llu,y:%llu\n",_x,_y);
  // create 2d vector to store the may points
  // _vecMap.resize(_x,vector<TSquare>(_y));
  _vecMap.resize(_x);
  for(ULL i=0; i<_x; i++) _vecMap[i].resize(_y);

  // put item and character threshold into an array
  float i[2] = {_fItemThreshold, _fCharacterThreshold};
  ULL o[3];
  // get the numbers of o[0]-Items, o[1]-Characters, o[2]-Empty
  _pInstance->getNumbers(i, o);
  // for increasing the game performence
  ULL numOfItems = o[0]<100?o[0]:100; //limit item num <=100
  ULL numOfCharacters = o[1]<100?o[1]:100; //limit enemy num <=100
  Debug("Item:%llu,Character:%llu", numOfItems, numOfCharacters);

  //TODO: for increasing game performence igorne this function.
  //    But if not init NULL square, there will be some issue.
  // initializeMap();

  // init all characters
  createCharacters(numOfCharacters);
  //init all items
  createItems(numOfItems);
}

// Function: initializeMap
//
// Description: initialize the map, but no use it, because to increase performence
//
// Return: void
void CMapManagement::initializeMap(){
  char empty = 'e';
  TSquare tSquare;
  // set square type that is empty
  tSquare.chType = 'e';
  // set square content is NULL or 'e'
  tSquare.uiContent.e = &empty;
  // using iterator to init all square.
  for(vector<vector <TSquare> >::iterator iter = _vecMap.begin(); iter != _vecMap.end(); ++iter){
    for(vector<TSquare>::iterator it = iter->begin(); it !=iter->end(); ++it){
      *it = tSquare;
    }
  }
}

// deconstruct function
CMapManagement::~CMapManagement(){
  // release vector content
  _vecCharacterPoints.clear();
  vector <TPoint>().swap(_vecCharacterPoints);
  delete _pCharManag;

  // release vector content
  _vecItemPoints.clear();
  vector <TPoint>().swap(_vecItemPoints);
  delete _pItemManag;
}

ULL CMapManagement::getWidth() const {
  return _x;
}

ULL CMapManagement::getHeight() const {
  return _y;
}

// Function: getNumbers
//
// Description: according to _fItemThreshold and _fCharacterThreshold calculate
//                    how many items, chararcters and empty.
//
// Parameter: 1.i[0]:threshold of Item
//            2.i[1]:threshold of Character
// Output Parameter: 1.o[0]:num of items
//                   2.o[1]:num of character
//                   3.o[2]:num of empty
//
// Return: void
void CMapManagement::getNumbers(float i[], ULL o[]){
  ULL num = _x * _y; // num of square
  o[0] = i[0]*num;
  o[1] = i[1]*num;
  o[2] = num-o[0]-o[1];
}

// Function: getRandomPosition
//
// Description: get a pair of random x and random y
//
// Return: TPosition - return a struct that content x, y
TPosition CMapManagement::getRandomPosition(){
  TPosition p;
  do {
    p.x=rand()%(_x);
    p.y=rand()%(_y);
  // test: if generated position of square has something, re-generate a position
  } while(!isSquareEmpty(p));
  return p;
}

// Function: createItems
//
// Description: call item management to create items for map
//
// Parameter: 1.number - num of items
//
// Return: void
void CMapManagement::createItems(ULL number){
  //Create a item management
  _pItemManag = CItemManagement::GetInstance();
  for(ULL i=0;i<number;i++){

  // create a item
  CItem* pItem = _pItemManag->createItem(getRandomItem(), getRandomDetail());
  // create a TSquare store type and item
  TSquare tSquare;
  // set the square type 'i'- item
  tSquare.chType = 'i';
  // set the square content
  tSquare.uiContent.i = pItem;

  // get a random position which is the coordination of the item.
  TPosition tPosition = getRandomPosition();

  // save the item and position into a TPoint
  TPoint tPoint;
  tPoint.s = tSquare;
  tPoint.p = tPosition;

  // save the tPoint into _vecItemPoints to manage.
  _vecItemPoints.push_back(tPoint);

  // TODO: Exception of _vecMap, If there is no _vecMap, need to create it firstly.
  _vecMap[tPosition.x][tPosition.y] = tSquare;
  }
}

// Function: createCharacters
//
// Description: call character management to create characters for map
//
// Parameter: 1.num of characters
//
// Return: void
void CMapManagement::createCharacters(ULL number){
  // Creat a character management
  _pCharManag = CCharacterManagement::GetInstance();
  for(ULL i=0;i<number;i++){
    // get a random race type
    EMCharacterRace emRace = getRandomCharacterRace();
    // Create a character
    CCharacter* pChar = _pCharManag->createCharacter(emRace);
    // create a TSquare store type and character
    TSquare tSquare;
    // set square type 'c'-character
    tSquare.chType = 'c';
    // set square content
    tSquare.uiContent.c = pChar;

    // get a random position which is the coordination of the character.
    TPosition tPosition = getRandomPosition();

    // save the character and position into a TPoint
    TPoint tPoint;
    tPoint.s = tSquare;
    tPoint.p = tPosition;

    // save the tPoint into _vecCharacterPoints to manage.
    _vecCharacterPoints.push_back(tPoint);

    // TODO: Exception of _vecMap, If there is no _vecMap, need to create it firstly.
    _vecMap[tPosition.x][tPosition.y] = tSquare;
  }
}

// Function: removeCharacter
//
// Description: remove a character from map management
//
// Parameter: 1.tPosition - the position which you want to remove a character
//
// Return: void
void CMapManagement::removeCharacter(TPosition tPosition){
  // using iterator to remove killed enemy
  vector<TPoint>::iterator it;
  for(it = _vecCharacterPoints.begin();it!=_vecCharacterPoints.end();){
    if((*it).p.x == tPosition.x && (*it).p.y == tPosition.y){
      _vecCharacterPoints.erase(it);
    }else{
      it++;
    }
  }
}

// Function: removeItem
//
// Description: remove an item from map management
//
// Parameter: 1.tPosition - the position which you want to remove a item
//
// Return: void
void CMapManagement::removeItem(TPosition tPosition){
  // manage items of map, if player pick up an item, delete it from the _vecItemPosints
  vector<TPoint>::iterator it;
  for(it = _vecItemPoints.begin();it!=_vecItemPoints.end();){
    if((*it).p.x == tPosition.x && (*it).p.y == tPosition.y){
      _vecItemPoints.erase(it);
    }else{
      it++;
    }
  }
}

// Function: getNumberOfCharacters
//
// Description: get current number of characters under map management
//
// Return: int - _vecCharacterPoints size
int CMapManagement::getNumberOfCharacters(){
  return _vecCharacterPoints.size();
}

// Function: getRandomCharacterRace
//
// Description: get a random race
//
// Return: EMCharacterRace - type of characters
EMCharacterRace CMapManagement::getRandomCharacterRace(){
  int _randomnumber=0;
  EMCharacterRace emRace;// character race
  _randomnumber=rand()%(5);
  switch(_randomnumber){
  case 0:
    emRace=HUMAN;
    break;
  case 1:
    emRace=ELF;
    break;
  case 2:
    emRace=DWARF;
    break;
  case 3:
    emRace=HOBBIT;
    break;
  case 4:
    emRace=ORC;
    break;
  }
  return emRace;
}

// Function: getRandomItem
//
// Description: get a random item type
//
// Return: EMItem - type of item
EMItem CMapManagement::getRandomItem(){
   int _randomnumber=0;
   EMItem emItem;// item type
   _randomnumber=rand()%(4);
   switch(_randomnumber){
   case 0:
     emItem=WEAPON;
     break;
   case 1:
     emItem=ARMOUR;
     break;
   case 2:
     emItem=SHIELD;
     break;
   case 3:
     emItem=RING;
     break;
   }
   return emItem;
}

// Function: getRandomDetail
//
// Description: get random detailed item, like geting a weapon,
//    there are 2 types(Sword & Dagger) in the weapon.
//
// TODO: if there are different types in an item, like weapon class needs to be
//    rewrite CWeapon class and create a weapon management class
//
// Return: int - detail type of item
int CMapManagement::getRandomDetail(){
   int detail=0;
   detail=rand()%(2);
   return detail;
}

// Function: getSquareValue
//
// Description: get a square with the square's position
//
// Parameter: 1.tPos - position of the square what you want to get
//
// Return: TSquare - the struct of square, include type and content of square
TSquare CMapManagement::getSquareValue(TPosition tPos) const{
  return _vecMap[tPos.x][tPos.y];
}

// Function: printSquareValue
//
// Description: print a square detail with the square's position
//
// Parameter: 1.tPos - the position of square which you hope print
//
// Return: void
void CMapManagement::printSquareValue(TPosition tPos) const {
  TSquare s = _vecMap[tPos.x][tPos.y];
  // Debug("[%llu][%llu] is the position of this square. type:%c", tPos.x, tPos.y, s.chType);
  MESSAGE("\nThis square is: [%llu][%llu]: ",tPos.x,tPos.y);
  if (s.chType == 'i'){
    // create a CItem* and let the pointer equal pointer of square's item
    CItem* pItem = s.uiContent.i;
    pItem->printItemDetails();
  }else if (s.chType == 'c') {
    // create a CCharacter* and let the pointer equal pointer of square's character
    CCharacter* pCharacter = s.uiContent.c;
    pCharacter->printCharacterDetails();
  }else{
    MESSAGE("This square is empty!");
  }
}

// Function: getSquareItem
//
// Description: set a item to a square with the square's position
//
// Parameter: 1.tPos - the square's position
//
// Return: CItem* - an item in the square
CItem* CMapManagement::getSquareItem(TPosition tPos) const{
  TSquare s = _vecMap[tPos.x][tPos.y];
  // create a CItem* and let it equals NULL
  CItem* pItem = NULL;
  if (s.chType == 'i') {
    // let the pointer equal square's item pointer
    pItem = s.uiContent.i;
  }
  return pItem;
}

// Function: getSquareCharacter
//
// Description: get a character with the square's position
//
// Parameter: 1.tPos - the square's position
//
// Return: CCharacter* - a character in the square
CCharacter* CMapManagement::getSquareCharacter(TPosition tPos) const {
  TSquare s = _vecMap[tPos.x][tPos.y];
  // create a CCharacter* and let it equals NULL
  CCharacter* pCharacter = NULL;
  if (s.chType == 'c') {
    // let the pointer equal square's enemy pointer
    pCharacter = s.uiContent.c;
  }
  return pCharacter;
}

// Function: clearSquare
//
// Description: remove the content of the square with the square's position
//
// Parameter: 1.tPos - the position of square which you want to clear or set NULL
//
// Return: void
void CMapManagement::clearSquare(TPosition tPos){
  Debug("Clear position is[%llu][%llu]", tPos.x, tPos.y);
  // char empty = 'e';
  TSquare s;
  // set the square's type is e-empty.
  s.chType = 'e';
  // set the square's content is NULL.
  s.uiContent.e = NULL;
  _vecMap[tPos.x][tPos.y] = s;
}

// Function: isSquareEmpty
//
// Description: judge: is there any thing in the square with square's position
//
// Parameter: 1.tPos - position of the square
//
// Return: bool - if the square is empty return true, else false.
bool CMapManagement::isSquareEmpty(TPosition tPos){
  TSquare s = _vecMap[tPos.x][tPos.y];
  if (s.chType != 'c' && s.chType != 'i') {
    // if the square isn't character and item, return true
    return true;
  }else{
    return false;
  }
}

// Function: setSquareItem
//
// Description: set a item to a square with the square's position
//
// Parameter: 1.pItem - the item will be put on the square
//            2.tPos - position of the square
//
// Return: void
void CMapManagement::setSquareItem(CItem* pItem, TPosition tPos){
  Debug("Drop position:[%llu][%llu]", tPos.x, tPos.y);
  TSquare s;
  s.chType = 'i';
  // create a new item
  CItem* i = new CItem();
  // copy content of item
  *i = *pItem;
  s.uiContent.i = i;

  TPoint t;
  t.s = s;
  t.p = tPos;

  _vecItemPoints.push_back(t);
  _vecMap[tPos.x][tPos.y] = s;
}

void CMapManagement::description(){}
