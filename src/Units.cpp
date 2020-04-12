#include "units.h"
#include "units_characteristics.h"
#include "helper_functions.h"


Warrior::Warrior (const std::string& fraction): Soldier (UC.at("warrior").at("health"),
		UC.at("warrior").at("damage_min"), UC.at("warrior").at("damage_max"),
		fraction, "warrior", UC.at("warrior").at("cost")) { }


Archer::Archer (const std::string& fraction): Soldier (UC.at("archer").at("health"),
		UC.at("archer").at("damage_min"), UC.at("archer").at("damage_max"),
		fraction, "archer", UC.at("archer").at("cost")) { }

void Archer::causeDamage(Soldier* enemy) const {
	double p = randomDouble();
	if (p < accuracy_) {
		int damage = randomInt(damage_min_, damage_max_);
		enemy->takeDamage(damage);
	}
}


Swordsman::Swordsman (const std::string& fraction): Soldier (UC.at("swordsman").at("health"),
		UC.at("swordsman").at("damage_min"), UC.at("swordsman").at("damage_max"),
		fraction, "swordsman", UC.at("swordsman").at("cost")) { }

