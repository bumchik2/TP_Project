#pragma once


#include "fractions.h"
#include "army_factory.h"
#include "army.h"
#include "units_characteristics.h"


#include <unistd.h>
#include <vector>
#include <string>
#include <iostream>


class Game {
public:
	Game(): player_fraction_(chooseFraction_()), player_factory_(getFactory(player_fraction_)),
			enemy_fraction_(chooseRandomFraction_({player_fraction_})), enemy_factory_(getFactory(enemy_fraction_)) {
		for (auto it : UC) {
			unit_types_available_.push_back(it.first);
		}
		choosePlayerArmy_();
		chooseEnemyArmy_();
	}
	void play();
private:
	static std::string chooseFraction_();
	static std::string chooseRandomFraction_(const std::vector<std::string>& banned_choices);

	std::string chooseSoldier_();
	void choosePlayerArmy_();
	void chooseEnemyArmy_();

	void buy_(const std::string& soldier_type);

	void updateParameters_();

	std::string player_fraction_;
	AbstractFactory* player_factory_;
	std::string enemy_fraction_;
	AbstractFactory* enemy_factory_;

	int player_money_ = 500;

	Army player_army_;
	Army enemy_army_;

	std::vector<std::string> unit_types_available_;
};




