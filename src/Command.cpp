#include "gameplay.h"
#include <iostream>
#include <stdexcept>


using std::cout;
using std::endl;


void FightCommand::execute() {
  while(game->enemy_army.getSize() != 0 && game->player_army.getSize() != 0) {
    sleep(1);
    cout << "Your army has " << game->player_army.getHP() << " HP in total. " <<
        game->player_army.getSize() << " soldiers are alive!" << endl;
    cout << "Enemy's army has " << game->enemy_army.getHP() << " HP in total. " <<
        game->enemy_army.getSize() << " soldiers are alive!" << endl;
    cout << "The armies are fighting!" << endl;
    game->player_army.fight(&(game->enemy_army));
    game->enemy_army.fight(&(game->player_army));
  }
}

void RecoverCommand::execute() {
  game->player_army.recover();
}

void TrainCommand::execute() {
  game->player_army.train();
}


void CommandExecutor::setCommand(Command* new_command) {
  if (command != 0) {
    delete command;
  }
  command = new_command;
}

void CommandExecutor::executeCommand() {
  if (command->game != game) {
    // an incorrect command was given
    throw std::invalid_argument("bad command value");
  }
  command->execute();

  delete command;
  // by doing so we make sure, no commands will be executed twice

  command = 0;
}

