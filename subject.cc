#include "subject.h"
#include "card.h"
#include "game.h"

void Subject::attach(std::shared_ptr<Observer> o) {
    observers.emplace_back(o);
}

void Subject::notifyObservers(Game &game) {
    for (size_t i = 0; i < observers.size(); ++i) {
        std::shared_ptr<Observer> ob = observers[i];

        // Remove observer if dead
        if (ob->shouldRemove()) {
            observers.erase(observers.begin() + i);
            --i;
            continue;
        }

        game.setActiveIndex(i);
        ob->notify(game);
    }
}
