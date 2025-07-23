#ifndef CARD_H
#define CARD_H
#include <string>
#include <memory>
#include "type.h"
#include "ability.h"
#include "abilitymanager.h"

class Game;
class Player;

class Card {
protected:
    static std::unique_ptr<AbilityManager> am;

    std::string name;
    int cost;
    int attack = 0;
    int defense = 0;
    int abilityCost = 0;
    int maxActions = 1;
    int actions = 0;
    std::string triggerType = "";
    std::string abilityDesc = "";
    Ability abilityFunc = nullptr;
    
    virtual void readInfo(std::string name) = 0;

public:
    Card();
    virtual ~Card();
    void useAbility(Game &game);

    // Utilities
    void takeDamage(int damage);
    void doDamage(Card &other);
    void doDamage(Player &p);
    void decreaseActions();
    void resetActions();
    bool isDead() const;

    // Getters
    std::string getName();
    size_t getCost();
    std::string getAbilityDesc();
    int getAbilityCost();
    int getAttack();
    int getDefense();
    int getMaxActions();
    int getActions();
    virtual CardType getType() = 0;

    // Setters
    void setAttack(int attack);
    void setDefense(int defense);
    void setMaxActions(int maxActions);
    void setActions(int actions);
    void setAbilityCost(int abilityCost);
};

#endif
