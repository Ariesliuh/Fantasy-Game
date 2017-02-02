// main.cpp
//
// Tower of Sorcerer
//
// author: Hang
// date: 13.11.2016
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <limits>

#include "map_management.h"
#include "display_management.h"
#include "chars_management.h"
#include "character.h"
#include "player.h"
#include "input_management.h"

using namespace std;
using namespace game;

unsigned long long readEdgeOfGameBoard(unsigned long long input);
int readCharacterInput(int input);

int main(int argc, char *argv[])
{
  MESSAGE("Welcome to the Fantasy Game!\n");
  unsigned long long x = 0, y = 0;
  int race = 0;
  int receiverace = 0;
  srand((unsigned)time(NULL));// set random seed

  //input X,Y
  MESSAGE("Please set the game board size by inserting x & y. \nx is:\n");
  x = readEdgeOfGameBoard(x);
  MESSAGE("y is:\n");
  y = readEdgeOfGameBoard(y);

  MESSAGE("\nPlease choose a character: (input the number): ");
  MESSAGE("\n  1.HUMAN\n  2.ELF\n  3.DWARF\n  4.HOBBIT\n  5.ORC\n");

  receiverace = readCharacterInput(receiverace);
  switch(receiverace){
  case 1:
    race=0;
    MESSAGE("You have chosen [Human] at [0][0]:");
    break;
  case 2:
    race=1;
    MESSAGE("You have chosen [Elf] at [0][0]:");
    break;
  case 3:
    race=2;
    MESSAGE("You have chosen [Dwarf] at [0][0]:");
    break;
  case 4:
    race=3;
    MESSAGE("You have chosen [Hobbit] at [0][0]:");
    break;
  case 5:
    race=4;
    MESSAGE("You have chosen [Orc] at [0][0]:");
    break;
  default:
    MESSAGE("Operation failed!\n");
    break;
  }

  Debug("creating character manag");
  // Creat a character management
  CCharacterManagement* pCharManag = CCharacterManagement::GetInstance();
  Debug("create character manag successfully");
  // Create a character for player
  CCharacter* pCharacter = pCharManag->createCharacter(EMCharacterRace(race));
  Debug("create character successfully");

  // Create a player role.
  CPlayer* pPlayer = CPlayer::GetInstance();
  Debug("get player instance successfully");
  pPlayer->setCharacter(pCharacter);
  Debug("set character to player successfully");

  // create map management object
  CMapManagement* pMapManagement = CMapManagement::GetInstance();
  pMapManagement->setMapRange(x, y);

  pPlayer->printDetials();
  MESSAGE("\nEnjoy!\n");
  pPlayer->look();
  // Create a input management
  CInputManagement* pInputManag = CInputManagement::GetInstance();
  // call the function that can receive the input and do the relative action
  pInputManag->inputOperations();

  // release the memory of object
  delete pCharacter;
  delete pCharManag;
  delete pInputManag;
  delete pMapManagement;
  return 0;
}

// Function: readEdgeOfGameBoard
//
// Description: check the input that must be number > 0
//
// Parameter: 1.input - user's input
//
// Return: unsigned long long - if user's input correct, return it
unsigned long long readEdgeOfGameBoard(unsigned long long input){
  while (!(cin >> input) || input==0){
    MESSAGE("Please input a right value(positive integer)!\n");
    // clear the input buffer
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  return input;
}

// Function: readCharacterInput
//
// Description: check the input that must be number > 0 and number<=5
//
// Parameter: 1.input - user's input
//
// Return: unsigned long long - if user's input correct, return it
int readCharacterInput(int input){
  while (!(cin >> input) || input<=0 || input>5){
    MESSAGE("Please select 1-5.\n");
    // clear the input buffer
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  return input;
}
