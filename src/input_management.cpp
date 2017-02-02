// input_management.cpp
//
// This is a file define a class which manages all input operations.
//
// author: Dongao
// date: 19.11.2016
#include "input_management.h"


using namespace std;
using namespace game;

CInputManagement* CInputManagement::_pInstance;

// construct function
CInputManagement::CInputManagement(){
  _pPlayer = CPlayer::GetInstance();
  _pDateTime = CDateTime::GetInstance();
}

// deconstruct function
CInputManagement::~CInputManagement(){
  delete _pDateTime;
}

// Function: GetInstance
//
// Description: using singleton to get one InputManagement instance.
//              If there is an instance, do nothing.
//
// Return: CInputManagement* - the executable only one instance
CInputManagement* CInputManagement::GetInstance(){
  if(_pInstance == NULL)
    _pInstance = new CInputManagement();
  return _pInstance;
}

// Function: inputOperations
//
// Description: using switch sentence to select and execute the raletive
//                    operations of input.
//
// Return: void
void CInputManagement::inputOperations(){
  char order;
  while(1){
    timeManagement();
    MESSAGE("\nPlease choose direction N,S,E,W or\n ");
    MESSAGE("command <A>ttack, <P>ickup, <D>rop, <L>ook, <I>nventory or e<X>it:");
    MESSAGE("\nplease input your order: ");
    cin>>order;
    if (order != 'x'){
      switch(order){
      case 'n':
      	upOperation();
      	break;
      case 's':
      	downOperation();
      	break;
      case 'e':
      	rightOperation();
      	break;
      case 'w':
      	leftOperation();
      	break;
      case 'p':
      	pickOperation();
      	break;
      case 'd':
      	dropOperation();
      	break;
      case 'a':
      	attackOperation();
      	break;
      case 'l':
      	lookOperation();
      	break;
      case 'i':
      	inventoryOperation();
      	break;
      default:
      	MESSAGE("\n please input right command!");
      	break;
      }
    }else{
      MESSAGE("\nYou went through %llu days.", _pDateTime->getDate());
      if(_pDateTime->getDate() == DAY){
        MESSAGE("\nAnd You operated %d steps.\n",
    		_pDateTime->getSteps());
      }else{
        // every 10 steps is 1 day
        // day_sum = date*10 + steps
        MESSAGE("\nAnd You operated %llu steps.\n", (_pDateTime->getDate()) * 10 + _pDateTime->getSteps());
      }
      MESSAGE("Total gold amout: %d",_pPlayer->getGold());
      MESSAGE("\nGAME OVER!\n");
      exitOperation();
    }
  }
}

// Function: upOperation
//
// Description: call the move function of pPlayer class, move to north
//
// Return: void
void CInputManagement::upOperation(){
  Debug("\n this is up operation!");
  _pPlayer->move(NORTH);
}

// Function: downOperation
//
// Description: call the move function of pPlayer class, move to south
//
// Return: void
void CInputManagement::downOperation(){
  Debug("\n this is down operation!");
  _pPlayer->move(SOUTH);
}

// Function: leftOperation
//
// Description: call the move function of pPlayer class, move to west
//
// Return: void
void CInputManagement::leftOperation(){
  Debug("\n this is left operation!");
  _pPlayer->move(WEST);
}

// Function: rightOperation
//
// Description: call the move function of pPlayer class, move to east
//
// Return: void
void CInputManagement::rightOperation(){
  Debug("\n this is right operation!");
  _pPlayer->move(EAST);
}

// Function: pickOperation
//
// Description: call the pickUpItem function of pPlayer class, pick the item
//                that in the current square
//
// Return: void
void CInputManagement::pickOperation(){
  Debug("\n this is pick operation!");
  _pPlayer->pickUpItem();
}

// Function: exitOperation
//
// Description: terminate the program
//
// Return: void
void CInputManagement::exitOperation(){
  Debug("\n this is exit operation!\n");
  exit(0);
}

// Function: dropOperation
//
// Description: call the dropItem function of pPlayer class, drop the item
//                that carried by player into the current square.
//
// Return: void
void CInputManagement::dropOperation(){
  Debug("\n this is drop operation!");
  _pPlayer->dropItem();
}

// Function: attackOperation
//
// Description: call the attackEnemy function of pPlayer class to attack enemy
//
// Return: void
void CInputManagement::attackOperation(){
  Debug("\n this is attack operation!");
  _pPlayer->attackEnemy();
}

// Function: lookOperation
//
// Description: call the look function of pPlayer class, print the item or enemy
//               information  that in the current square
//
// Return: void
void CInputManagement::lookOperation(){
  Debug("\n this is look operation!");
  _pPlayer->look();
}

// Function: inverntoryOperation
//
// Description: call the info function of pPlayer class, print the information
//                of player, include state and equipment
//
// Return: void
void CInputManagement::inventoryOperation(){
  Debug("\n this is inventory operation!");
  _pPlayer->info();
}

// Function: timManagement
//
// Description: call the countSteps function of pDateTime,
//                to show the current time and step.
//
// Return: void
void CInputManagement::timeManagement(){
  // ever input need to record.
  _pDateTime->countSteps();
  MESSAGE("\n\n***************current round***************");
  if (_pDateTime->getTime() == DAY) {
    MESSAGE("\nThis is daytime(%d).", _pDateTime->getSteps());
  }else {
    MESSAGE("\nThis is nighttime(%d).", _pDateTime->getSteps());
  }
}
