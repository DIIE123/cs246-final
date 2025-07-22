#ifndef CARD_H
#define CARD_H
#include <string>

class Card {
protected:
    std::string name;
    int cost;
    virtual void readInfo(std::string name) = 0;

public:
    Card();
    virtual ~Card();
    // virtual void useAbility();
    // virtual void play();

    std::string getName();
    int getCost();
};

#endif
