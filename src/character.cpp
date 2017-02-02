// character.cpp
//
// This is file defines a class which defines Character class.
//
// author: Hang
// date: 13.11.2016
#include "character.h"

using namespace game;
using namespace std;

// Function: printCharacterDetailS
//
// Description: print the information of characters.
//
// Return: void
void CCharacter::printCharacterDetails(){
  Debug("This is Character Details");
  MESSAGE("\nThis square is occupied by %s", _strRaceName.c_str());
  MESSAGE("\n Attack=%d ; ", _nAttack);
  MESSAGE(" AttackChance=%f . ", _fAttackChance);
  MESSAGE("\n Defense=%d ; ", _nDefense);
  MESSAGE(" DefenseChance=%f . ", _fDefenseChance);
  MESSAGE("\n Health=%d ; ", _nHealth);
  MESSAGE(" Strength=%d . ", _nStrength);
}

// Function: update
//
// Description: inherit CObserver, listening the datetime change. Mostly,
//                it will be implement in subclass.
//
// Parameter: 1.&msg - if date time has changed, this function will received notification.
//
// Return: void
void CCharacter::update(const std::string &msg){
  calculateAttack();
  calculateDefense();
  calculateStrength();
  calculateHealth();
}

int CCharacter::getAttack() const{
  return _nAttack;
}

int CCharacter::getDefense() const{
  return _nDefense;
}

int CCharacter::getHealth() const{
  return _nHealth;
}

int CCharacter::getStrength() const{
  return _nStrength;
}

float CCharacter::getAttackChance() const{
  return _fAttackChance;
}

float CCharacter::getDefenseChance() const{
  return _fDefenseChance;
}

float CCharacter::getSufferAttackRate() const{
  return _fSufferAttackRate;
}

int CCharacter::getSufferHurt() const{
  return _nSufferHurt;
}

int CCharacter::getCalculateHealth() {
  int nHealth = calculateHealth();
  return nHealth;
}

// Function: calculateAttack
//
// Description: calculate the current attack value of character,
//                include all the items addition that carried by character.
//
// Return: int
int CCharacter::calculateAttack(){
  // define a varible and init its value equal character attack value
  int nAttack = _nAttack;
  if (_pWeapon) {
    // add weapon attack value
    nAttack += _pWeapon->getAttack();
  }
  if (_pArmour) {
    // add armour attack value
    nAttack += _pArmour->getAttack();
  }
  if (_pShield) {
    // add shield attack value
    nAttack += _pShield->getAttack();
  }
  if (!_vecRing.empty()){
    for(vector<CRing>::iterator it = _vecRing.begin(); it != _vecRing.end(); ++it){
      // add ring attack value
      nAttack += (*it).getAttack();
    }
  }
  return nAttack;
}

// Function: calculateDefense
//
// Description: calculate the current defense value of character,
//                include all the items addition that carried by character.
//
// Return: int
int CCharacter::calculateDefense(){
  int nDefense = _nDefense;
  if (_pWeapon) {
    nDefense += _pWeapon->getDefense();
  }
  if (_pArmour) {
    nDefense += _pArmour->getDefense();
  }
  if (_pShield) {
    nDefense += _pShield->getDefense();
  }
  if (!_vecRing.empty()){
    for(vector<CRing>::iterator it = _vecRing.begin(); it != _vecRing.end(); ++it){
      nDefense += (*it).getDefense();
    }
  }
  return nDefense;
}

// Function: printstate
//
// Description: print the character current state.
//
// Return: void
void CCharacter::printstate(){
  MESSAGE("\n Attack=%d ;", calculateAttack());
  MESSAGE(" AttackChance=%f", _fAttackChance);
  MESSAGE("\n Defense=%d ;", calculateDefense());
  MESSAGE(" DefenseChance=%f", _fDefenseChance);
  MESSAGE("\n Health=%d ;", calculateHealth());
  MESSAGE(" Strength=%d / %d .",getCarryingWeight(),calculateStrength());
}

// Function: calculateStrength
//
// Description: calculate the current strength value of character,
//                include all the items addition that carried by character.
//
// Return: int
int CCharacter::calculateStrength(){
  int nStrength = _nStrength;
  if (_pWeapon) {
    nStrength += _pWeapon->getStrength();
  }
  if (_pArmour) {
    nStrength += _pArmour->getStrength();
  }
  if (_pShield) {
    nStrength += _pShield->getStrength();
  }
  if (!_vecRing.empty()){
    for(vector<CRing>::iterator it = _vecRing.begin(); it != _vecRing.end(); ++it){
      nStrength += (*it).getStrength();
    }
  }
  return nStrength;
}

// Function: calculateHealth
//
// Description: calculate the current health value of character,
//                include all the items addition that carried by character.
//
// Return: int
int CCharacter::calculateHealth(){
  int nHealth=_nHealth;
  if (_pWeapon) {
    nHealth += _pWeapon->getHealth();
  }
  if (_pArmour) {
    nHealth += _pArmour->getHealth();
  }
  if (_pShield) {
    nHealth += _pShield->getHealth();
  }
  if (!_vecRing.empty()){
    for(vector<CRing>::iterator it = _vecRing.begin(); it != _vecRing.end(); ++it){
      nHealth += (*it).getHealth();
    }
  }
  return nHealth;
}

// Function: attack
//
// Description: attack operation. if character attack successful, function
//                will call the defense function to judge whether the opposite
//                defense successful, if defence success opposite doesn't hurt,
//                if not, the opposite will get hurt. There are two round,
//                player round and enemy round
//
// Parameter: 1.pc - CCharacter class pointer
//            2.round - attack round, round=1 is player round,
//                      round=2 is enemy round .
//
// Return: void
void CCharacter::attack(CCharacter* pc, int round){
  // init _fSufferAttackRate and _nSufferHurt
  initialRound(pc);
  if(successRate(_fAttackChance)){
    if(round==1){
      MESSAGE(" Player attack successful; ");
    }else{
      MESSAGE(" Enemy attack successful; ");
    }
    pc->defense(round);
    if(calculateAttack()-pc->calculateDefense() >= 0 ){
      // health = (real damage) * (suffer attack rate) + (extra damage (for hobbit))
      pc->_nHealth -= (calculateAttack()-pc->calculateDefense())*pc->getSufferAttackRate()+_nSufferHurt;}
    nFlat=1;
  }else {
    if(round==1){
      MESSAGE(" Player attack miss.\n");
    }else{
      MESSAGE(" Enemy attack miss.\n");
    }
    nFlat=0;
  }
}

// Function: defense
//
// Description: defense operation, get the defense successful chance and to
//                set the character's special ability.
//
// Parameter: 1.round - round=1 is player round, round=2 is enemy round .
//
// Return: void
void CCharacter::defense(int round){
  if(successRate(_fDefenseChance)){
    if(round==2){
      MESSAGE("Player defense successful. \n");
    }else{
      MESSAGE("Enemy defense successful. \n");
    }
    specialAbility();// call the special ability function
  }else {
    if(round==2){
      MESSAGE("Player defense failed. \n ");
    }else{
      MESSAGE("Enemy defense failed. \n ");
    }
  }
}

// Function: play
//
// Description: complete the player attack operation and enemy attack operation,
//                nflat is the record of attact successful, if player attack
//                successful, the enemy will attack the player, if not,
//                the enemy will do nothing.
//
// Parameter: 1.pc - CCharacter class pointer
//
// Return: void
void CCharacter::play(CCharacter* pc){
  // judge whether the character is exist or not
  if(!pc) return;
  // call attack function
  attack(pc,1);
  // pc is exsit or not
  if(!pc) return;
  // judge whether the character is alive or not
  if(pc->_nHealth <= 0){
    return;
  }
  //if player attack successful, the enemy will attack the player
  if (nFlat==1){
    // pc is exsit or not
    if(!pc) return;
    // pc call attack function
    pc->attack(this,2);
  }else{
    return;
  }
}

// Function: initialRound
//
// Description: in the beginning of a round, characters need set initial value
//                of their special ability.
//
// Parameter: 1.pc - CCharacter class pointer
//
// Return: void
void CCharacter::initialRound(CCharacter* pc){
  // initialize the sufferHurt
  _nSufferHurt = 0;
  // initialize the sufferAtteckRate
  _fSufferAttackRate = 1;
  pc->_nSufferHurt = 0;
  pc->_fSufferAttackRate = 1;
}

// Function: successRate
//
// Description: according to the attack and defense success rate of character
//                to produce a bool value, if success return turn, if not
//                return false
//
// Parameter: 1.nRate - character attack or defense successful rate
//
// Return: bool
bool CCharacter::successRate(float nRate){
  // get a random number
  unsigned int unTemp = rand()%10;
  Debug("Successful Rate[%d], Now Rate[%f]", unTemp, nRate);
  // judge whether character attack or defense success
  if(nRate>(unTemp/10.0))
    return true;
  else
    return false;
}

CWeapon* CCharacter::getWeapon() const {
  return _pWeapon;
}

// Function: setWeapon
//
// Description: when the player pick up a weapon, this function will
//                change relative value for player, if the player don't
//                have enough strength, the weapon cannot be picked.
//
// Parameter: 1.pWeapon - CWeapon class pointer
//
// Return: void
void CCharacter::setWeapon(CWeapon* pWeapon) {
  if (pWeapon == NULL) {
    _pWeapon = NULL;
  }else if (canSetItem(pWeapon)) {
    _pWeapon = pWeapon;
  }else{
    MESSAGE("You don't have strength to carry it");
  }
}

CShield* CCharacter::getShield() const {
  return _pShield;
}

// Function: setShield
//
// Description: when the player pick up a shield, this function will
//                change relative value for player, if the player don't
//                have enough strength, the shield cannot be picked.
//
// Parameter: 1.pShield - CShield class pointer
//
// Return: void
void CCharacter::setShield(CShield* pShield) {
  if (pShield == NULL) {
    _pShield = NULL;
  }else if (canSetItem(pShield)) {
    _pShield = pShield;
  }else{
    MESSAGE("You don't have strength to carry it");
  }
}

CArmour* CCharacter::getArmour() const {
  return _pArmour;
}

// Function: setArmour
//
// Description: when the player pick up an armour, this function will
//                change relative value for player, if the player don't
//                have enough strength, the armour cannot be picked.
//
// Parameter: 1.pArmour - CArmour class pointer
//
// Return: void
void CCharacter::setArmour(CArmour* pArmour) {
  if (pArmour == NULL) {
    _pArmour = NULL;
  // judge character can take the item(strength > weight) can be taken.
  }else if (canSetItem(pArmour)) {
    _pArmour = pArmour;
  }else{
    MESSAGE("You don't have strength to carry it");
  }
}

vector<CRing> CCharacter::getRing() const {
  return _vecRing;
}

// Function: setRing
//
// Description: when the player pick up a ring, this function will
//                change relative value for player, if the player don't
//                have enough strength, the ring cannot be picked.
//
// Parameter: 1.pRing - CRing class pointer
//
// Return: void
void CCharacter::setRing(CRing* pRing){
  // judge character can take the item(strength > weight) can be taken.
  if (canSetItem(pRing)) {
    // push the ring into _vecRing to manage
    _vecRing.push_back(*pRing);
  }else{
    MESSAGE("You don't have strength to carry it");
  }
}

// Function: removeRing
//
// Description: remove a ring from _vecRing
//
// Parameter: 1.nIndex - index of _vecRing
//
// Return: void
void CCharacter::removeRing(int nIndex){
  _vecRing.erase(_vecRing.begin()+nIndex);
}

// Function: getCarryingWeight
//
// Description: calculate the current items weight value that
//                carried by character.
//
// Return: int
int CCharacter::getCarryingWeight() {
  int nWeight = 0;
  if (_pWeapon) {
    nWeight += _pWeapon->getWeight();
  }
  if (_pArmour) {
    nWeight += _pArmour->getWeight();
  }
  if (_pShield) {
    nWeight += _pShield->getWeight();
  }
  if (!_vecRing.empty()) {
    for (vector<CRing>::iterator it = _vecRing.begin(); it != _vecRing.end(); ++it) {
      nWeight += it->getWeight();
    }
  }
  return nWeight;
}

// Function: canSetItem
//
// Description: calculate the carrying items weight value that carried by
//                character,and the current strength value of character,
//                and to judge whether the player can carry more items.
//
// Parameter: 1.pItem - CItem class pointer
//
// Return: boll
bool CCharacter::canSetItem(CItem* pItem){
  //calculate the residue strength value of player
  int n = calculateStrength() - getCarryingWeight();
  if (n>=pItem->getWeight()) return true;
  else return false;
}

void CCharacter::description(){
  MESSAGE("\nThis is the Character class");
}
