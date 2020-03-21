#include "army_factory.h"
#include "fractions.h"


#include <string>
#include <vector>


ArmyFactory::ArmyFactory (const std::string& fraction) : fraction_(fraction) { }


Soldier* ArmyFactory::createUnit (const std::string& unit_type) {
	Soldier* new_soldier = 0;
	if (unit_type == "warrior") {
		new_soldier = new Warrior (fraction_);
	} else if (unit_type == "archer") {
		new_soldier = new Archer (fraction_);
	} else if (unit_type == "swordsman") {
		new_soldier = new Swordsman (fraction_);
	} else {
		// incorrect unit_type
	}
	if (new_soldier != 0) {
		units_.push_back(new_soldier);
	}
	return new_soldier;
}


ArmyFactory::~ArmyFactory () {
	for (unsigned i = 0; i < units_.size(); ++i) {
		delete units_[i];
	}
}

