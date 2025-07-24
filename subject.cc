#include "subject.h"
#include "observer.h"

void Subject::attach(Observer *o) {
    observers.emplace_back(o);
}

void Subject::detach() {
    observers.pop_back();
}

void Subject::notifyObservers(Game &game) {
    for (auto &ob : observers) ob->notify(game);
}
