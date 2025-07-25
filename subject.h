#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <memory>

class Game;
class Observer;

class Subject {
    std::vector<std::shared_ptr<Observer>> observers;
  public:
    void attach(std::shared_ptr<Observer> o);  
    void removeObservers();
    void notifyObservers(Game &game);
};

#endif
