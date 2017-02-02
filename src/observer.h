// observer.h
//
// observer header
// This file define an oberver mode to listen datetime change event
//
// author: Hang
// date: 16.11.2016
#ifndef observer_h
#define observer_h

#include <iostream>
#include <cstdlib>

namespace game {
  class CObserver;
  
  // CObserverSubject
  // This is subject of observer, observer will listening instance of
  //    CObserverSubject, when an observer is register.
  //
  // author: Hang Liu
  // data: 16.11.2016
  class CObserverSubject{
  public:
    CObserverSubject(){};
    virtual ~CObserverSubject(){};
    // register an observer and put it into observer list
    virtual void registerObserver(CObserver* obs) = 0;
    // remove an observer from observer list
    virtual void removeObserver(CObserver* obs) = 0;
    // notify observers with msg
    virtual void notifyObserver(const std::string &msg) = 0;
  };
  class CObserver {
  public:
    virtual ~CObserver(){};
    // when an observer has be register, subject will notify listener.
    //    listener's update function will be triggered.
    virtual void update(const std::string &msg) = 0;
  protected:
    CObserver(){};
  };
}
#endif
