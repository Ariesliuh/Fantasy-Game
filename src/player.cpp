// player.cpp
//
// This is an adapter file, define some players operation,
//    which is different from enemy.
//
// author: Hang
// date: 13.11.2016
#include "player.h"

using namespace game;
using namespace std;

CPlayer* CPlayer::_pInstance;

// construct function
CPlayer::CPlayer(){
  _pMapManag = CMapManagement::GetInstance();
  // initial position of player
  _tPos.x = 0;
  _tPos.y = 0;
}

CPlayer::~CPlayer(){}

// Function: GetInstance
//
// Description: get the instance of CPlayer.
//
// Return: CPlayer* - this is the instance of player
CPlayer* CPlayer::GetInstance(){
  if(_pInstance == NULL)
    _pInstance = new CPlayer();
  return _pInstance;
}

// Function: setCharacter
//
// Description: get the instance of CPlayer.
//                to call this function, after calling GetInstance().
//
// Parameter: 1.character - player selected character(Human, Orc, Elf, etc.)
//
// Return: void
void CPlayer::setCharacter(CCharacter *character){
  if(_pCharacter == NULL){
    _pCharacter = character;
  }
}

// Function: attackEnemy
//
// Description: attack operation
//
// Return: void
void CPlayer::attackEnemy(){
  CCharacter* pEnemy = _pMapManag->getSquareCharacter(_tPos);
  if (pEnemy == NULL){
    MESSAGE("\nThere is no enemy!");
    return;
  }
  // If enemy health is more than zero, player can attack. And there are two
  //    round that is player round and enemy round,
  if(pEnemy->getHealth() > 0){
    _pCharacter->play(pEnemy);
    MESSAGE("\nPlayer: ");
    _pCharacter->printstate();
    MESSAGE("\nEnemy: ");
    pEnemy->printstate();
  }
  // if the enemy is dead, player will get the gold and enemy will be clean
  //    from map and character vector
  if(pEnemy->getHealth() <= 0){
    setGold(pEnemy->getDefense());
    MESSAGE("\nYou defeated the enemy successfully!");
    MESSAGE("\nYou earned %d golds.",pEnemy->getDefense());
    _pMapManag->removeCharacter(_tPos);
    _pMapManag->clearSquare(_tPos);
  }
  judgeDead();
}

// Function: getPosition()
//
// Description: get current position
//
// Return: TPosition
TPosition CPlayer::getPosition() const{
  return _tPos;
}


// Function: move
//
// Description: control player to move, a move command can let player move 1 step.
//
// Parameter: 1.orien - move direction, include south, east, west and north.
//
// Return: void
void CPlayer::move(EMOrientation orien){
  switch(orien){
  case NORTH:
    // If player current position is not in the northernmost
    //    the player can move to north
    if (_tPos.y > 0) {
      _tPos.y = (_tPos.y-1)>0 ? _tPos.y-1 : 0;
    }
    break;
  case SOUTH:
    // If player current position is not in the southernmost
    //    the player can move to south
    _tPos.y = (_tPos.y+1)<_pMapManag->getHeight() ? _tPos.y+1 : _pMapManag->getHeight()-1;
    break;
  case EAST:
    // If player current position is not in the easternmost
    //    the player can move to east
    _tPos.x = (_tPos.x+1)<_pMapManag->getWidth() ? _tPos.x+1 : _pMapManag->getWidth()-1;
    break;
  case WEST:
    // If current position is not in the westernmost
    //    the player can move to west
    if (_tPos.x>0){
      _tPos.x = (_tPos.x-1)>0 ? _tPos.x-1 : 0;
    }
    break;
  }
  look();
}

// Function: look
//
// Description: look operation, call the function of map_management class
//                to print the value of this square
//
// Return: void
void CPlayer::look(){
  // Call the print function of map_management to show the item and enemy in
  //    current square
  _pMapManag->printSquareValue(_tPos);
}

// Function: pickUpItem
//
// Description: pick up operation, pick the item in current square.
//
// Return: void
void CPlayer::pickUpItem(){
  Debug("Pick up position is[%llu][%llu]", _tPos.x, _tPos.y);
  // Judge is there anything in the square.
  CItem* pItem = _pMapManag->getSquareItem(_tPos);
  EMItem emType;
  // judge the square is empty or not
  if (pItem == NULL) {
    MESSAGE("There is nothing to carry.");
    // if there is nothing, return directly.
    return;
  } else {
    emType = pItem->getItemType(); // get the type of item
  }
  // Judge the item's type and the judge whether the player can carry it.
  if (emType == WEAPON) {
    if (_pCharacter->getWeapon() == NULL) {
      // force transform the pItem pointer into CWPeapon* and set it to character's weapon pointer
      _pCharacter->setWeapon((CWeapon*)pItem);
      // clean square's item pointer
      _pMapManag->clearSquare(_tPos);
      MESSAGE("\nYou pick it up successfully!");
    }else{
      MESSAGE("\nYou already have a weapon, can only carry one weapon!");
    }
  } else if(emType == ARMOUR) {
    if (_pCharacter->getArmour() == NULL) {
      _pCharacter->setArmour((CArmour*)pItem);
      _pMapManag->clearSquare(_tPos);
      MESSAGE("\nYou pick it up successfully!");
    }else{
      MESSAGE("\nYou already have a armour, can only carry one armour!.");
    }
  }else if(emType == SHIELD) {
    if (_pCharacter->getShield() == NULL) {
      _pCharacter->setShield((CShield*)pItem);
      _pMapManag->clearSquare(_tPos);
      MESSAGE("\nYou pick it up successfully!");
    }else{
      MESSAGE("\nYou already have a shield, can only carry one shield!.");
    }
  }else{
    _pCharacter->setRing((CRing*)pItem);
    // the strength ring will reduce the health,
    //    so need to judge the health of player when player pick it up
    judgeDead();
    _pMapManag->clearSquare(_tPos);
    MESSAGE("\nYou pick it up successfully!");
  }
  // remove the item info from _vecItemPoints, take the item to CPlayer to manage.
  _pMapManag->removeItem(_tPos);
}

// Function: info
//
// Description: print the information of character include current state
//                and equipment infomation
//
// Return: void
void CPlayer::info(){
  CWeapon* _pWeapon=_pCharacter->getWeapon();
  CArmour* _pArmour=_pCharacter->getArmour();
  CShield* _pShield=_pCharacter->getShield();
  vector<CRing> _vecRing=_pCharacter->getRing();

  Debug("INFO function");
  if (_pWeapon==NULL){
    MESSAGE("\n You don't have any weapon.");
  }else{
    _pWeapon->printInfo();
  }

  if (_pArmour==NULL){
    MESSAGE("\n You don't have any armour.");
  }else{
    _pArmour->printInfo();
  }

  if (_pShield==NULL){
    MESSAGE("\n You don't have any shield.");
  }else{
    _pShield->printInfo();
  }

  if(_vecRing.empty()){
    MESSAGE("\n You don't have any ring.");
  }else{
    for (vector<CRing>::iterator it = _vecRing.begin(); it != _vecRing.end(); ++it) {
      it->printInfo();
    }
  }
  MESSAGE("\n");

  //call the printstate function of character class to show the player state
  _pCharacter->printstate();
  MESSAGE("\n You are carrying: %d gold pieces.",_nGold);
  MESSAGE("\n");
}

// Function: dropItem
//
// Description: drop the items (weapon, armour, shield, rings)
//
// Return: void
void CPlayer::dropItem(){
  Debug("DROP ITEM FUNCTION");
  int size = 3; // The ring verctor number
  // The serial number of item, to judge whether the input of player is right
  int weapon = 1, armour = 2, shield = 3, ring = 4;
  if (!_pMapManag->isSquareEmpty(_tPos)) {
    MESSAGE("You can not drop item here");
    return;
  }
  if(_pCharacter->getWeapon() || _pCharacter->getArmour() || _pCharacter->getShield() || !_pCharacter->getRing().empty()){
    if (_pCharacter->getWeapon()) {
      MESSAGE("\nIf you want drop the weapon, please input [1].  ");
      _pCharacter->getWeapon()->printInfo();
      weapon = 0;
    }
    if (_pCharacter->getArmour()) {
      MESSAGE("\nIf you want drop the armour, please input [2].  ");
      _pCharacter->getArmour()->printInfo();
      armour = 0;
    }
    if (_pCharacter->getShield()) {
      MESSAGE("\nIf you want drop the shield, please input [3].  ");
      _pCharacter->getShield()->printInfo();
      shield = 0;
    }
    if (!_pCharacter->getRing().empty()) {
      vector<CRing> _vecRing=_pCharacter->getRing();
      MESSAGE("\nIf you want drop the rings, please input :");
      ring = 0;
      for(vector<CRing>::iterator it = _vecRing.begin(); it != _vecRing.end(); ++it){
        size++;
        // print ring information
        it->printInfo();
        MESSAGE(" :  [%d] ",size );
      }
    }
  }else{
    MESSAGE("\nYou don't have any item! \n");
    return;
  }
  // Receive the input of player and judge it whether it is correct
  readInput(weapon,armour,shield,ring,size);
}

// Function: getGold
//
// Description: get the gold amount of character
//
// Return: int
int CPlayer::getGold() const{
  return _nGold;
}

// Function: setGold
//
// Description: calculate the gold amount
//
// Return: void
void CPlayer::setGold(int nGold){
  _nGold = _nGold + nGold;
}

// Function: specialAbility
//
// Description: every character has their race, every race has different ability.
//
// Return: void
void CPlayer::specialAbility(){
  _pCharacter->specialAbility();
}

// Function: printDeatials
//
// Description: print the character detials
//
// Return: void
void CPlayer::printDetials(){
  MESSAGE(" \n Attack=%d", _pCharacter->getAttack());
  MESSAGE(" \n AttackChance=%f", _pCharacter->getAttackChance());
  MESSAGE(" \n Defense=%d", _pCharacter->getDefense());
  MESSAGE(" \n DefenseChance=%f", _pCharacter->getDefenseChance());
  MESSAGE(" \n Health=%d", _pCharacter->getHealth());
  MESSAGE(" \n Strength=%d", _pCharacter->getStrength());
}

// Function: judgeDead
//
// Description: judge whether the character is dead
//
// Return: void
void CPlayer::judgeDead(){
  int health;
  // Get the current health value
  health=_pCharacter->getCalculateHealth();
  // Get the time instance
  CDateTime* _pDateTime = CDateTime::GetInstance();
  if (health <= 0){
    MESSAGE("\nYou are dead!");
    MESSAGE("\nTotal gold amount: %d",_nGold);
    MESSAGE("\nYou went through %llu days.", _pDateTime->getDate());
    if(_pDateTime->getDate() == DAY){
      MESSAGE("\nAnd You operated %d steps.\n", _pDateTime->getSteps());
    }else{
      // every 10 steps is 1 day
      // day_sum = date*10 + steps
      MESSAGE("\nAnd You operated %llu steps.\n", (_pDateTime->getDate()) * 10 + _pDateTime->getSteps());
    }
    _pMapManag->~CMapManagement();
    MESSAGE("\nGAME OVER!\n ");
    // exit the game
    exit(0);
  } else if (_pMapManag->getNumberOfCharacters()==0){
    MESSAGE("\nYou WIN!");
    MESSAGE("\nTotal gold amount: %d",_nGold);
    MESSAGE("\nYou went through %llu days.", _pDateTime->getDate());
    if(_pDateTime->getDate() == DAY){
      MESSAGE("\nAnd You operated %d steps.\n", _pDateTime->getSteps());
    }else{
      // every 10 steps is 1 day
      // day_sum = date*10 + steps
      MESSAGE("\nAnd You operated %llu steps.\n", (_pDateTime->getDate()) * 10 + _pDateTime->getSteps());
    }
    _pMapManag->~CMapManagement();
    MESSAGE("\nGAME OVER!\n ");
    // exit the game
    exit(0);
  }
}

// Function: readInput
//
// Description: judge whether the input number of player is corrent and
//                do the relative of drop operations that is put the item
//                in map vector and clean the charater bag
//
// Return: void
void CPlayer::readInput(int weapon, int armour, int shield, int ring, int size){
  int i;
  MESSAGE("\n");
  //Judge which serial number can be received
  while(!(cin>>i) || i<1 || i>size || i== weapon || i==armour || i==shield || i==ring){
    // if player input wrong selection, the game need clear the input buffer and reminder player re-input
    MESSAGE("\nOperation failed! please select again!");
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  if (i==1) {
    _pMapManag->setSquareItem(_pCharacter->getWeapon(), _tPos);
    _pCharacter->setWeapon(NULL);
  }else if (i==2) {
    _pMapManag->setSquareItem(_pCharacter->getArmour(), _tPos);
    _pCharacter->setArmour(NULL);
  }else if (i==3) {
    _pMapManag->setSquareItem(_pCharacter->getShield(), _tPos);
    _pCharacter->setShield(NULL);
  }else {
    _pMapManag->setSquareItem(&(_pCharacter->getRing()[i-4]), _tPos);
    _pCharacter->removeRing(i-4);
    judgeDead();
  }
  MESSAGE("\nYou drop it successfully!");
}
