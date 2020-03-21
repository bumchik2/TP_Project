#pragma once

#include "helper_functions.h"
#include "soldier.h"
#include <string>
#include <vector>
#include <iostream>


const std::vector<std::string> UNIT_TYPES = {
	"warrior",
	"archer",
	"swordsman"
};


class Warrior : public Soldier {
public:
	Warrior(const std::string& fraction);
};


class Archer : public Soldier {
public:
	Archer(const std::string& fraction);

	void causeDamage (Soldier* enemy) const override;
private:
	const double accuracy_ = 0.8;
};


class Swordsman : public Soldier {
public:
	Swordsman(const std::string& fraction);
};

