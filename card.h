#ifndef CARD_H
#define CARD_H
#include <string>
#include <memory>
#include "type.h"
#include "ability.h"
#include "abilitymanager.h"
#include "triggertype.h"
#include "observer.h"

class Game;
class Player;

class Card: public Observer {
protected:
    static std::shared_ptr<AbilityManager> am;

    std::string name;
    int cost;
    int attack = 0;
    int defense = 0;
    int abilityCost = 0;
    int maxActions = 1;
    int actions = 0;
    bool isTarget = false;
    TriggerType triggerType = TriggerType::None;
    std::string abilityDesc = "";
    Ability abilityFunc = nullptr;
    Player &player;
    
    virtual void readInfo(std::string name) = 0;

public:
    Card(Player &player);
    virtual ~Card();
    virtual bool useAbility(Game &game);

    // Utilities
    void takeDamage(int damage);
    void doDamage(Card &other);
    void doDamage(Player &p);
    void decreaseActions();
    void resetActions();
    bool isDead();

    TriggerType convertToTriggerType(std::string input);
    void notify(Game &game) override;
    bool shouldRemove() override;

    // Getters
    Player &getPlayer();
    std::string getName();
    virtual int getCost();
    std::string getAbilityDesc();
    virtual int getAbilityCost();
    virtual int getAttack();
    virtual int getDefense();
    virtual int getEnchantmentCost();
    virtual int getMaxActions();
    virtual bool getHasAbility();
    virtual std::string getEnchantmentName();
    virtual std::string getAttackString();
    virtual std::string getDefenseString();
    virtual std::string getEnchantmentDesc();
    int getActions();
    TriggerType getTriggerType();
    virtual CardType getType() = 0;
    virtual std::shared_ptr<Card> getPointer();
    bool getIsTarget();

    // Setters
    void setAttack(int attack);
    void setDefense(int defense);
    void setMaxActions(int maxActions);
    void setActions(int actions);
    void setAbilityCost(int abilityCost);
};

#endif
