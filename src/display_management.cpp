// display_mangement.cpp
//
// This is a management file to manage the way of display.
//
// author: Hang
// date: 13.11.2016
#include "display_management.h"

using namespace game;
using namespace std;

CDisplayManagement* CDisplayManagement::_pInstance;

// construct function
CDisplayManagement::CDisplayManagement(){}

// deconstruct function
CDisplayManagement::~CDisplayManagement(){};

// Function: GetInstance
//
// Description: this is a singleton function. there is only one instance in this game
//
// Return: CDisplayManagement* - instance of CDisplayManagement
CDisplayManagement* CDisplayManagement::GetInstance(){
  if(_pInstance == NULL)
    _pInstance = new CDisplayManagement();
  return _pInstance;
}

void CDisplayManagement::description(){
  MESSAGE("This is the Display Mangement class");
}
