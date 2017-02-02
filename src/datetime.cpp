// datetime.cpp
//
// this is management file of datetime
//
// author: Hang
// date: 19.11.2016
#include "datetime.h"

using namespace game;
using namespace std;

CDateTime* CDateTime::_pInstance;

// Function: GetInstance()
//
// Description: get the instance of CDateTime.
//
// Return: CDateTime* - this is the instance of datetime
CDateTime* CDateTime::GetInstance(){
  if(_pInstance == NULL)
    _pInstance = new CDateTime();
  return _pInstance;
}

// constructor
CDateTime::CDateTime(){
  // initialize the properties
  _emTime = DAY;
  _nSteps = 0;
  _unllDate = -1;
}

// destructor
CDateTime::~CDateTime(){}

// Function: registerObserver
//
// Description: register an observer and put it into observer list(_observers)
//
// Parameter: 1.obs - this is a listener
//
// Return: void
void CDateTime::registerObserver(CObserver* obs){
  _observers.push_back(obs);
}

// Function: removeObserver
//
// Description: remove an observer from observer list(_observers)
//
// Parameter: 1.obs - this is a listener
//
// Return: void
void CDateTime::removeObserver(CObserver* obs){
  if (_observers.size()>0) {
    _observers.remove(obs);
  }
}

// Function: notifyObserver
//
// Description: notify observers with msg
//
// Parameter: 1.&msg - notification message
//
// Return: void
void CDateTime::notifyObserver(const string &msg){
  list<CObserver*>::iterator it = _observers.begin();
  for ( ;it != _observers.end(); it++) {
    (*it)->update(msg);
  }
}

EMDateTime CDateTime::getTime() const{
  return _emTime;
}

int CDateTime::getSteps() const{
  return _nSteps;
}

unsigned long long CDateTime::getDate() const{
  return _unllDate;
}

// Function: countSteps
//
// Description: calculate the steps according the command number
//
// void
void CDateTime::countSteps(){
  ++_nSteps;
  // calculate steps when player input a command
  _nSteps = (_nSteps-1)%10+1;
  // when steps number is ten, then the steps will become zero, and count again
  _unllDate += _nSteps==1?1:0;// one day has ten steps
  if (_nSteps>5) {
    _emTime = NIGHT;
    // notify listener, now is night
    notifyObserver("NIGHT");
  }else{
    _emTime = DAY;
    // notify listener, now is daytime
    notifyObserver("DAY");
  }
}

void CDateTime::description(){
  MESSAGE("This is the datetime class");
}
