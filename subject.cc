#include "subject.h"
#include "observer.h"

void Subject::attach(std::shared_ptr<Observer> o) {
    observers.emplace_back(o);
}

void Subject::detach(size_t index) {
  observers.erase(observers.begin() + index);
}

void Subject::notifyObservers(Game &game) {
    for (auto &ob : observers) ob->notify(game);
}
