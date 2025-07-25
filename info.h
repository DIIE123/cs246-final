#ifndef INFO_H
#define INFO_H
#include "type.h"
#include <string>

struct CardInfo {
  std::string name;
  size_t cost;
  size_t damage;
  size_t health;
  std::string modification;
  size_t activationCost;
  size_t charge;
  std::string description;
  
  CardInfo(std::string name, size_t cost, size_t damage, size_t health, std::string description, size_t activationCost);
  CardInfo(std::string name, size_t cost, std::string description);
  CardInfo(std::string name, size_t cost, std::string description, std::string modification);
  CardInfo(std::string name, size_t cost, std::string description, size_t activationCost, size_t charge);
  virtual ~CardInfo() = default;
  virtual CardType getType() = 0;
  
};

struct MinionInfo: public CardInfo {

  MinionInfo(std::string name, size_t cost, size_t damage, size_t health, std::string description, size_t activationCost);
  ~MinionInfo() = default;
  CardType getType() override;
};

struct SpellInfo: public CardInfo{

  SpellInfo(std::string name, size_t cost, std::string description);
  ~SpellInfo() = default;
  CardType getType() override;
};

struct EnchantInfo: public CardInfo {

  EnchantInfo(std::string name, size_t cost, std::string description, std::string modification);
  ~EnchantInfo() = default;
  CardType getType() override;
};

struct RitualInfo: public CardInfo {

  RitualInfo(std::string name, size_t cost, std::string description, 
             size_t activationCost, size_t charge);
  ~RitualInfo() = default;
  CardType getType() override;
};

#endif
