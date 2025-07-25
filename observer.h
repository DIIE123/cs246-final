#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;
class Game;

class Observer {
  public:
    virtual void notify(Game &game) = 0; 
    virtual bool shouldRemove() = 0; 
    virtual ~Observer() = default;
};

#endif
