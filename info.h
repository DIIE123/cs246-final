#ifndef INFO_H
#define INFO_H
#include <string>

enum class CardType {
  Minion,
  Spell,
  Enchantment,
  Ritual
};

struct CardInfo {
  std::string name;
  size_t cost;
  CardInfo(std::string, size_t cost);
  virtual ~CardInfo() = default;
  virtual CardType getType() = 0;
};

struct MinionInfo: public CardInfo {
  size_t damage;
  size_t health;

  MinionInfo(std::string name, size_t cost, size_t damage, size_t health);
  ~MinionInfo() = default;
  CardType getType() override;
};

struct SpellInfo: public CardInfo{
  std::string description;

  SpellInfo(std::string name, size_t cost, std::string description);
  ~SpellInfo() = default;
  CardType getType() override;
};

struct EnchantInfo: public CardInfo {
  std::string modification;

  EnchantInfo(std::string name, size_t cost, std::string modification);
  ~EnchantInfo() = default;
  CardType getType() override;
};

struct RitualInfo: public CardInfo {
  std::string description;
  size_t activationCost;
  size_t charge;

  RitualInfo(std::string name, size_t cost, std::string description, 
             size_t activationCost, size_t charge);
  ~RitualInfo() = default;
  CardType getType() override;
};

#endif
