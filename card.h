#ifndef CARD_H
#define CARD_H
#include <string>

class Card {
protected:
    std::string name;
    size_t cost;
    virtual void readInfo(std::string name) = 0;

public:
    Card();
    virtual ~Card();
    // virtual void useAbility();
    // virtual void play();

    std::string getName();
    size_t getCost();
};

#endif
