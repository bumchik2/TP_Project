#pragma once


#include <map>
#include <string>


static const std::map<std::string, std::map<std::string, int>> UC = { // Units_Characteristics
		{"warrior", {{"health", 100}, {"damage_min", 15}, {"damage_max", 30}, {"cost", 80}}},
		{"archer", {{"health", 70}, {"damage_min", 20}, {"damage_max", 40}, {"cost", 100}}},
		{"swordsman", {{"health", 200}, {"damage_min", 30}, {"damage_max", 50}, {"cost", 150}}}
};

