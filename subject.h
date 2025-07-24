#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

class Observer;
class Game;

class Subject {
    std::vector<Observer*> observers;
  public:
    void attach(Observer *o);  
    void detach();
    void notifyObservers(Game &game);
};

#endif
