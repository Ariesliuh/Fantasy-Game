// datetime.h
//
// datetime header
//
// author: Hang
// date: 19.11.2016
#ifndef datetime_h
#define datetime_h

#include <iostream>
#include <cstdlib>
#include <list>

#include "observer.h"
#include "display_management.h"

namespace game {
  // enum of datetime
  typedef enum EMDateTime{
    DAY = 0,
    NIGHT
  } emDateTime;

  // CDateTime
  // This is time management class
  //
  // author: Hang Liu
  // data: 19.11.2016
  class CDateTime: public CObserverSubject{
  public:
    virtual ~CDateTime();
    // get the instance
    static CDateTime* GetInstance();
    // get the current time
    EMDateTime getTime() const;
    // get the current steps, (1-10) if step beyond 10, _ullDate+1
    int getSteps() const;
    // get the current days
    unsigned long long getDate() const;
    // calculate the datetime when player input every command
    void countSteps();
    void description();

    // put an observer into notification list to manage.
    void registerObserver(CObserver* obs);
    // remove an object from notification list
    void removeObserver(CObserver* obs);
    // send a message to every observer which is in the notification list
    void notifyObserver(const std::string &msg);

  protected:
    std::string _status;
  private:
    CDateTime();
    static CDateTime* _pInstance;
    // day or night
    EMDateTime _emTime;
    // current steps, common steps<10
    int _nSteps;
    // every 10 steps is 1 date.(5 steps is a day, 5 steps is a night)
    unsigned long long _unllDate;
    // notification list
    std::list<CObserver* > _observers;
  };
}
#endif
