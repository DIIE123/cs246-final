#include "card.h"
#include "player.h"
#include <iostream>
#include <memory>

std::shared_ptr<AbilityManager> Card::am = std::make_shared<AbilityManager>();

Card::Card(Player &player): player{player} {}
Card::~Card() {}

bool Card::useAbility(Game &game) {
    if (getHasAbility()) return abilityFunc(game);
    return false;
}

// Utilities
void Card::takeDamage(int damage) {
    setDefense(getDefense() - damage);
}

void Card::doDamage(Card &other) {
    other.takeDamage(getAttack());
    takeDamage(other.getAttack());
    decreaseActions();
}

void Card::doDamage(Player &player) {
    player.takeDamage(getAttack());
    decreaseActions();
}

void Card::decreaseActions() {
    setActions(getActions() - 1);
}

void Card::resetActions() {
    setActions(getMaxActions());
}

bool Card::isDead() {
    return getDefense() <= 0;
}

TriggerType Card::convertToTriggerType(std::string input) {
    if (input == "Start") return TriggerType::Start;
    if (input == "End") return TriggerType::End;
    if (input == "Enter") return TriggerType::Enter;
    if (input == "Leave") return TriggerType::Leave;
    return TriggerType::None;
}

void Card::notify(Game &game) {
    useAbility(game);
}

bool Card::shouldRemove() {
    return isDead();
}

// Getters
Player &Card::getPlayer() { return player; }
std::string Card::getName() { return name; }
int Card::getCost() { return cost; }
std::string Card::getAbilityDesc() { return abilityDesc; }
int Card::getAbilityCost() { return abilityCost; }
int Card::getAttack() { return attack; }
int Card::getDefense() { return defense; }
int Card::getActions() { return actions; }
int Card::getMaxActions() { return maxActions; }
bool Card::getHasAbility() { return true || (getType() == CardType::Minion && triggerType != TriggerType::None); }
int Card::getEnchantmentCost() { return 0; }
TriggerType Card::getTriggerType() { return triggerType; }
std::string Card::getAttackString() { return ""; }
std::string Card::getDefenseString() { return ""; }
std::shared_ptr<Card> Card::getPointer() {return nullptr; }
bool Card::getIsTarget() { return isTarget; }
std::string Card::getEnchantmentName() { return ""; }
std::string Card::getEnchantmentDesc() { return ""; }

// Setters
void Card::setAttack(int attack) { this->attack = attack; }
void Card::setDefense(int defense) { this->defense = defense; }
void Card::setMaxActions(int maxActions) { this->maxActions = maxActions; }
void Card::setActions(int actions) { this->actions = actions; }
void Card::setAbilityCost(int abilityCost) { this->abilityCost = abilityCost; }
