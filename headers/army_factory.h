#pragma once


#include "units.h"
#include "heroes.h"
#include <vector>
#include <string>


class AbstractFactory {
public:
	AbstractFactory(const std::string& fraction_);
	virtual ~AbstractFactory();

	Soldier* createUnit (const std::string& unit_type);
	virtual Hero* Leader() { return 0; }

protected:
	std::vector<Soldier*> units_;
	std::string fraction_;
};


class FrenchFactory : public AbstractFactory {
public:
	FrenchFactory();
	~FrenchFactory();
	Hero* Leader() override;
private:
	Hero* leader_;
};


class EnglishFactory : public AbstractFactory {
public:
	EnglishFactory();
	~EnglishFactory();
	Hero* Leader() override;
private:
	Hero* leader_;
};


class GermanFactory : public AbstractFactory {
public:
	GermanFactory();
	~GermanFactory();
	Hero* Leader() override;
private:
	Hero* leader_;
};


static AbstractFactory* getFactory (const std::string& fraction) {
	if (fraction == "France") {
		return new FrenchFactory();
	} else if (fraction == "England") {
		return new EnglishFactory();
	} else if (fraction == "Germany") {
		return new GermanFactory();
	} else {
		throw std::runtime_error ("unknown fraction");
	}
}

