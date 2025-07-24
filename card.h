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
    size_t cost;
    size_t attack = 0;
    size_t defense = 0;
    size_t abilityCost = 0;
    size_t maxActions = 1;
    size_t actions = 0;
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
    virtual size_t getAbilityCost();
    virtual size_t getAttack();
    virtual size_t getDefense();
    virtual size_t getMaxActions();
    size_t getActions();
    virtual CardType getType() = 0;

    // Setters
    void setAttack(size_t attack);
    void setDefense(size_t defense);
    void setMaxActions(size_t maxActions);
    void setActions(size_t actions);
    void setAbilityCost(size_t abilityCost);
};

#endif
