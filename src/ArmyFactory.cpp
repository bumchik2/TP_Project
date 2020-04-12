#include "units.h"
#include "army_factory.h"
#include "fractions.h"


#include <string>
#include <vector>
#include <iostream>

AbstractFactory::AbstractFactory (const std::string& fraction) : fraction_(fraction) { }

Soldier* AbstractFactory::createUnit (const std::string& unit_type) {
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

AbstractFactory::~AbstractFactory () {
	for (unsigned i = 0; i < units_.size(); ++i) {
		delete units_[i];
	}
}


FrenchFactory::FrenchFactory() : AbstractFactory("France"), leader_(new Napoleon()) { }

FrenchFactory::~FrenchFactory() {
	delete leader_;
}

Hero* FrenchFactory::Leader() {
	return leader_;
}


EnglishFactory::EnglishFactory() : AbstractFactory("England"), leader_(new Elizabeth()) { }

EnglishFactory::~EnglishFactory() {
	delete leader_;
}

Hero* EnglishFactory::Leader() {
	return leader_;
}


GermanFactory::GermanFactory() : AbstractFactory("Germany"), leader_(new Bismarck()) { }

GermanFactory::~GermanFactory() {
	delete leader_;
}

Hero* GermanFactory::Leader() {
	return leader_;
}


FactoryCacher factory_cacher;


AbstractFactory* FactoryCacher::getFactory(const std::string& fraction) {
	if (fraction == "France") {
		if (french_factory_ == 0) {
			french_factory_ = new FrenchFactory();
		}
		return french_factory_;
	} else if (fraction == "England") {
		if (english_factory_ == 0) {
			english_factory_ = new EnglishFactory();
		}
		return english_factory_;
	} else if (fraction == "Germany") {
		if (german_factory_ == 0) {
			german_factory_ = new GermanFactory();
		}
		return german_factory_;
	} else {
		throw std::runtime_error ("unknown fraction");
	}
}


AbstractFactory* getFactory (const std::string& fraction) {
	return factory_cacher.getFactory(fraction);
}

