#pragma once


#include <string>
#include "action.h"


class Action;


class Soldier {
public:
  Soldier(int health, int damage_min, int damage_max,
      const std::string& fraction, const std::string& type, int cost);
  virtual ~Soldier();

  void takeDamage (int damage);
  virtual void causeDamage (Soldier* enemy) const;
  bool isAlive() const;
  void Die();

  void updateParameters();

  void printInfo() const;

protected:
  Action* action_ = 0;

  int max_health_;
  int health_;
  int damage_min_;
  int damage_max_;
  bool is_alive_ = true;

  std::string fraction_ = 0;
  std::string type_ = 0;

  int cost_;

  friend class Army;
  friend class Action;
  friend class RecoverAction;
  friend class TrainAction;
};

