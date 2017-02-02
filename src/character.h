// character.h
//
// header of character
//
// author: Hang
// date: 13.11.2016
#ifndef character_h
#define character_h

#include <iostream>
#include <cstdlib>
#include <vector>

#include "observer.h"
#include "display_management.h"
#include "weapon.h"
#include "ring.h"
#include "shield.h"
#include "armour.h"

namespace game {
  // EMCharacterRace
  // This is a list of race
  //
  // author: Hang
  // data: 13.11.2016
  enum EMCharacterRace {
    HUMAN = 0,
    ELF,
    DWARF,
    HOBBIT,
    ORC
  };

  // state of character, there is no used.
  typedef enum EMCharacterStatus {
    IDLE = 0,
    ATTACK,
    DEFENSE
  } emCharacterStatus;

  // CCharacter
  // This is a super class of Player and Enemy
  //
  // author: Hang
  // data: 13.11.2016
  class CCharacter: public CObserver{
  public:
    virtual ~CCharacter(){};
    // inherit CObserver
    void update(const std::string &msg);
    // every character have their own special ability
    virtual void specialAbility(){};
    // get the character attack value
    int getAttack() const;
    // get the character defense value
    int getDefense() const;
    // get the character health value
    int getHealth() const;
    // get the character strength value
    int getStrength() const;
    // get the character attack successful chance
    float getAttackChance() const;
    // get the character defense successful chance
    float getDefenseChance() const;
    // get the special ability of character
    float getSufferAttackRate() const;
    // get the special ability of character
    int getSufferHurt() const;
    // get the health include the addition value of item
    int getCalculateHealth();
    // print the character detailed information
    void printCharacterDetails();
    // print the character general information
    void printstate();
    // complete the attack and defense operation
    void play(CCharacter* pc);
    // get the attack and defense success rate
    bool successRate(float nRate);
    CWeapon* getWeapon() const;
    void setWeapon(CWeapon* pWeapon);
    CShield* getShield() const;
    void setShield(CShield* pShield);
    CArmour* getArmour() const;
    void setArmour(CArmour* pArmour);
    std::vector<CRing> getRing() const;
    void setRing(CRing* pRing);
    // according to index of ring to remove a ring
    void removeRing(int nIndex);
    // get all weight of item that player carrying
    int getCarryingWeight();
    void description();

  protected:
    std::string _strRaceName;
    int _nAttack;
    float _fAttackChance;
    int _nDefense;
    float _fDefenseChance;
    int _nHealth;
    int _nStrength;
    // suffer attack rate, if _fSufferAttackRate = 0, means never cause damage.
    //    if _fSufferAttackRate = 1, means cause 100% damage.
    float _fSufferAttackRate;
    // extra damage. this value for hobbit to record 0-5 random damage.
    //    if _nSufferHurt = (0-5), _fSufferAttackRate = 0, means hobbit has successful a defense
    //    if _nSufferHurt = 0, _fSufferAttackRate = 1, means hoobit has failed a defense
    int _nSufferHurt;
    int _nCarryingWeight;

    // inventory list
    CWeapon* _pWeapon;
    CShield* _pShield;
    CArmour* _pArmour;
    std::vector<CRing> _vecRing;

  private:
    // record whether the character attack successful
    int nFlat;
    // cal attack value
    int calculateAttack();
    // cal defense value
    int calculateDefense();
    // cal strength value
    int calculateStrength();
    // cal health value
    int calculateHealth();
    bool canSetItem(CItem* pItem);
    // initialize the value in the beginnig
    void initialRound(CCharacter* pc);
    // attack operation
    void attack(CCharacter* pc,int round);
    // defense operation
    void defense(int round);
  };
}
#endif
