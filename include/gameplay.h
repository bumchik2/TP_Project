#pragma once


#include "fractions.h"
#include "army_factory.h"
#include "army.h"
#include "units_characteristics.h"


#include <unistd.h>
#include <vector>
#include <string>
#include <iostream>


class Command;
class Game;


class CommandExecutor {
public:
	CommandExecutor(Game* game): game(game) { }
	void setCommand(Command* new_command);
	void executeCommand();
private:
	Command* command = 0;
	Game* game;
};


class Game {
public:
  Game(): player_fraction(chooseFraction_()), player_factory(getFactory(player_fraction)) {
    for (const auto& it : UC) {
      unit_types_available_.push_back(it.first);
    }
    choosePlayerArmy_();
  }

  ~Game() { delete command_executor; }

  void play();

  std::string player_fraction;
  AbstractFactory* player_factory;
  std::string enemy_fraction;
  AbstractFactory* enemy_factory;

  Army player_army;
  Army enemy_army;

private:

  static std::string chooseFraction_();
  static std::string chooseRandomFraction_(const std::vector<std::string>& banned_choices);

  std::string chooseSoldier_();
  void choosePlayerArmy_();
  void chooseEnemyArmy_();

  void buy_(const std::string& soldier_type);

  void updateParameters_();

  int player_money_ = 500;

  std::vector<std::string> unit_types_available_;

  CommandExecutor* command_executor = new CommandExecutor(this);
};


class Command {
public:
  Command(Game* game): game(game) { }
  virtual ~Command() = default;
  virtual void execute() { };
protected:
  Game* game;

  friend class CommandExecutor;
};

class FightCommand : public Command {
public:
  FightCommand(Game* game): Command(game) { }
  void execute() override;
};

class RecoverCommand : public Command {
public:
  RecoverCommand(Game* game): Command(game) { }
  void execute() override;
};

class TrainCommand : public Command {
public:
  TrainCommand(Game* game): Command(game) { }
  void execute() override;
};


