#include "soldier.h"
#include "fractions.h"
#include "helper_functions.h"
#include <algorithm>
#include <iostream>
#include "action.h"


Soldier::Soldier (int health, int damage_min, int damage_max,
		const std::string& fraction, const std::string& type, int cost):
		max_health_(health), health_(health), damage_min_(damage_min),
		damage_max_(damage_max), fraction_(fraction), type_(type), cost_(cost) {
		action_ = new Action(this);
	}

Soldier::~Soldier() { }

bool Soldier::isAlive() const {
	return is_alive_;
}

void Soldier::Die() {
	is_alive_ = false;
}

void Soldier::takeDamage(int damage) {
	health_ = std::max(0, health_ - damage);
	if (health_ == 0) {
		Die();
	}
}

void Soldier::causeDamage(Soldier* enemy) const {
	int damage = randomInt(damage_min_, damage_max_);
	enemy->takeDamage(damage);
}

void Soldier::printInfo() const {
	std::cout << type_ << " from " << fraction_ << " has " << health_ << " hp left. ";
}


void Soldier::updateParameters() {
	if (action_ != 0) {
		action_->updateParameters();
	}
}

