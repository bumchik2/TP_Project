#pragma once


#include "units.h"
#include <vector>
#include <string>


class ArmyFactory {
public:
	ArmyFactory(const std::string& fraction_);
	~ArmyFactory();

	Soldier* createUnit (const std::string& unit_type);
private:
	std::vector<Soldier*> units_;
	std::string fraction_;
};

