#include <algorithm>
#include <iostream>
#include "action.h"


void RecoverAction::updateParameters() {
	soldier_->health_ = std::min(soldier_->max_health_, soldier_->health_ + healing_rate_);
}

void TrainAction::updateParameters() {
	soldier_->damage_min_ += training_rate_;
	soldier_->damage_max_ += training_rate_;
}

