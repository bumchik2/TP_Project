#include "army_factory.h"
#include "army.h"
#include "units_characteristics.h"
#include "units.h"
#include "gameplay.h"
#include "observer.h"


#include <unistd.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>


using std::cin;
using std::cout;
using std::endl;


template<typename T>
T chooseParameter (const std::string& parameter_name, const std::vector<T>& v, const std::string& hint = "") {
  T result;
  while (std::find(v.begin(), v.end(), result) == v.end()) {
    cout << "Choose " << parameter_name << ": " << v << ". " << hint << endl;
    cout << "(You need to type the full name of your choice without changes.)" << endl;
    cin >> result;
  }
  return result;
}


template<typename T>
T chooseRandomParameter (const std::vector<T>& to_choose_from, const std::vector<T>& banned_choices) {
  int index = rand() % to_choose_from.size();
  while (std::find(banned_choices.begin(), banned_choices.end(), to_choose_from[index]) != banned_choices.end()) {
    index = rand() % to_choose_from.size();
  }
  return to_choose_from[index];
}


int chooseNumberBetween (const std::string& parameter_name, int l, int r) {
  int result = -1000 * 1000 * 1000;
  while (result < l || result > r) {
    cout << "Choose " << parameter_name << ": " <<
        "number between " << l << " and " << r << '.' << endl;
    cin >> result;
  }
  return result;
}


std::string Game::chooseFraction_ () {
  return chooseParameter("fraction", FRACTIONS);
}


std::string Game::chooseRandomFraction_ (const std::vector<std::string>& banned_choices) {
  return chooseRandomParameter (FRACTIONS, banned_choices);
}


std::string toString(unsigned a) {
  if (a == 0) {
    return "0";
  }
  std::string result;
  while (a != 0) {
    char tmp = a % 10;
    std::string start;
    start += (tmp + '0');
    result = start + result;
    a /= 10;
  }
  return result;
}


std::string Game::chooseSoldier_ () {
  std::stringstream hint;
  for (unsigned i = 0; i < unit_types_available_.size(); ++i) {
    if (i != 0) {
      hint << ", ";
    }
    hint << unit_types_available_[i] << " costs ";
    hint << UC.at(unit_types_available_[i]).at("cost");
    if (i + 1 == unit_types_available_.size()) {
      hint << ".";
    }
  }
  hint << " You have " << toString(player_money_) << " left.";
  return chooseParameter("type of unit", unit_types_available_, hint.str());
}


void Game::buy_(const std::string& soldier_type) {
  if (UC.at(soldier_type).at("cost") <= player_money_) {
    player_army.addSoldier(player_factory->createUnit(soldier_type));
    player_money_ -= UC.at(soldier_type).at("cost");
  } else {
    cout << "You don't have enough money!" << endl;
  }
}


void Game::choosePlayerArmy_() {
  std::vector<int> unit_costs;
  for (unsigned i = 0; i < unit_types_available_.size(); ++i) {
    unit_costs.push_back(UC.at(unit_types_available_[i]).at("cost"));
  }
  int min_cost = unit_costs[0];
  for (unsigned i = 0; i < unit_costs.size(); ++i) {
    min_cost = std::min(min_cost, unit_costs[i]);
  }
  while (player_money_ >= min_cost) {
    std::string soldier = chooseSoldier_();
    buy_(soldier);
  }
}


void Game::chooseEnemyArmy_() {
  for (unsigned i = 0; i < 3; ++i) {
    std::string soldier_type = unit_types_available_[rand() % unit_types_available_.size()];
    enemy_army.addSoldier(enemy_factory->createUnit(soldier_type));
  }
}


void Game::updateParameters_() {
  cout << "You can choose if you want to recover units health or train!" << endl;
  std::string recover_or_train = chooseParameter("what your army will do",
      std::vector<std::string>{"recover", "train"});
  if (recover_or_train == "recover") {
    command_executor->setCommand(new RecoverCommand(this));
    command_executor->executeCommand();
  } else {
    command_executor->setCommand(new TrainCommand(this));
    command_executor->executeCommand();
  }
}


void Game::play() {
  int waves_survived = 0;
  while (player_army.getSize() != 0) {
	enemy_fraction = chooseRandomFraction_({player_fraction});
	enemy_factory = getFactory(enemy_fraction);
	chooseEnemyArmy_();

    cout << "You are fighting against " << enemy_fraction << "!" << endl;

    Observer observer;
    observer.addListener(PlayerVictory, player_factory->Subscriber());
    observer.addListener(PlayerDefeat, enemy_factory->Subscriber());

    command_executor->setCommand(new FightCommand(this));
    command_executor->executeCommand();

    if (player_army.getSize() != 0) {
      cout << endl << "You survived another Wave! Good job!" << endl;
      observer.notify(PlayerVictory);
      cout << endl;
      ++waves_survived;

      updateParameters_();
    } else {
      cout << endl;
      observer.notify(PlayerDefeat);
    }
  }
  cout << "Game Over! You survived " << waves_survived << " waves!" << endl;
}

