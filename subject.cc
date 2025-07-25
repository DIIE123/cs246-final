#include "subject.h"
#include "card.h"
#include "game.h"

void Subject::attach(std::shared_ptr<Observer> o) {
    observers.emplace_back(o);
}

void Subject::removeObservers() {
    for (size_t i = 0; i < observers.size(); ++i) {
        std::shared_ptr<Observer> ob = observers[i];
        if (ob->shouldRemove()) {
            observers.erase(observers.begin() + i);
            --i;
        }
    }
}

void Subject::notifyObservers(Game &game) {
    for (size_t i = 0; i < observers.size(); ++i) {
        std::shared_ptr<Observer> ob = observers[i];

        game.setActiveIndex(i);
        ob->notify(game);
    }
}
