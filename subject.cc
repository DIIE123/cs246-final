#include "subject.h"
#include "observer.h"
#include "game.h"

void Subject::attach(std::shared_ptr<Observer> o) {
    observers.emplace_back(o);
}

void Subject::detach(size_t index) {
  observers.erase(observers.begin() + index);
}

void Subject::notifyObservers(Game &game) {
    for (size_t i = 0; i < observers.size(); ++i) {
        std::shared_ptr<Observer> ob = observers[i];
        game.setActiveIndex(i);
        ob->notify(game);
    }
}
