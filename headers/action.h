#pragma once


#include "soldier.h"


class Soldier;


class Action {
public:
	Action(Action* action): soldier_(action->soldier_) { }
	Action(Soldier* soldier): soldier_(soldier) { }
	virtual ~Action() = default;
	virtual void updateParameters() { while (true) { } }
protected:
	Soldier* soldier_;
};


class RecoverAction : public Action {
public:
	RecoverAction(Action* action): Action(action) { }
	void updateParameters() override;
private:
	int healing_rate_ = 5;
};


class TrainAction : public Action {
public:
	TrainAction(Action* action): Action(action) { }
	TrainAction() = delete;
	void updateParameters() override;
private:
	int training_rate_ = 2;
};

