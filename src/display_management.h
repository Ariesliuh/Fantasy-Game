// display_management.h
//
// display_management header
//
// author: Hang
// date: 13.11.2016
#ifndef display_management_h
#define display_management_h

#include <iostream>
#include <cstdlib>
#include <cstdio>

#define TEXT 1
#ifdef TEXT
#define MESSAGE(fmt, args...) printf(fmt, ##args)
#else
#define MESSAGE(fmt, args...)
#endif

//#define DEBUG 1
#ifdef DEBUG
#define Debug(fmt, args...) printf(fmt, ##args)
#else
#define Debug(fmt, args...)
#endif

namespace game {

  // CDisplayManagement
  // The class as an interface between user and game.
  //    Now just use display words. It will support UI in futhure.
  //
  // author: Hang Liu
  // data: 13.11.2016
  class CDisplayManagement{
  public:
    ~CDisplayManagement();
    // get instance function
    static CDisplayManagement* GetInstance();
    void description();

  private:
    CDisplayManagement();
    // the instance
    static CDisplayManagement* _pInstance;
  };
}
#endif
