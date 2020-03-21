#pragma once


#include "helper_functions.h"
#include "fractions.h"
#include "army_factory.h"


#include <iostream>


using std::cin;
using std::cout;
using std::endl;


void chooseFraction (std::string& fraction) {
	bool fraction_chosen = false;
	while (!fraction_chosen) {
		cout << "choose a fraction (enter the full name):" << endl;
		cout << FRACTIONS;
		cin >> fraction;
		if (contains(FRACTIONS, fraction)) {
			fraction_chosen = true;
		}
	}
}


void chooseSoldier(std::string& unit_type) {
	bool unit_chosen = false;
	while (!unit_chosen) {
		cout << "choose a soldier_type (enter the full name):" << endl;
		cout << UNIT_TYPES;
		cin >> unit_type;
		if (contains(UNIT_TYPES, unit_type)) {
			unit_chosen = true;
		}
	}
}


void Fight (Soldier* player_soldier, Soldier* enemy_soldier) {
	while (player_soldier->isAlive() && enemy_soldier->isAlive()) {
		player_soldier->printInfo();
		enemy_soldier->printInfo();
		std::string foo;
		cout << "your unit is attacking! enter any word to continue" << endl;
		cin >> foo;
		player_soldier->causeDamage(enemy_soldier);
		if (!enemy_soldier->isAlive()) {
			break;
		}
		player_soldier->printInfo();
		enemy_soldier->printInfo();
		cout << "your unit is being attacked! enter any word to continue" << endl;
		cin >> foo;
		enemy_soldier->causeDamage(player_soldier);
	}
	if (player_soldier->isAlive()) {
		cout << "You win!" << endl;
	} else {
		cout << "You lose!" << endl;
	}
}


void playGame() {

	std::string player_fraction;
	chooseFraction(player_fraction);
	ArmyFactory playerFactory (player_fraction);

	std::string player_soldier_type;
	chooseSoldier(player_soldier_type);
	Soldier* player_soldier = playerFactory.createUnit(player_soldier_type);

	std::string enemy_fraction = player_fraction;
	while (enemy_fraction == player_fraction) {
		enemy_fraction = FRACTIONS[rand() % FRACTIONS.size()];
	}
	ArmyFactory enemyFactory (enemy_fraction);

	std::string enemy_soldier_type = UNIT_TYPES[rand() % UNIT_TYPES.size()];
	Soldier* enemy_soldier = enemyFactory.createUnit(enemy_soldier_type);

	Fight(player_soldier, enemy_soldier);

}

