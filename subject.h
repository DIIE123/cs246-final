#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <memory>

class Observer;
class Game;

class Subject {
    std::vector<std::shared_ptr<Observer>> observers;
  public:
    void attach(std::shared_ptr<Observer> o);  
    void detach(size_t index);
    void notifyObservers(Game &game);
};

#endif
