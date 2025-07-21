#ifndef CARD_H
#define CARD_H
#include <string>

class Card {
protected:
    std::string name;
    int cost;
public:
    Card();
    virtual ~Card();
    // virtual void play();

    std::string getName();
    int getCost();
};

#endif
