#pragma once


#include "units.h"
#include "heroes.h"
#include "observer.h"

#include <vector>
#include <string>


class AbstractFactory {
public:
  AbstractFactory(const std::string& fraction_);
  virtual ~AbstractFactory();

  Soldier* createUnit (const std::string& unit_type);
  Hero* Leader();
  Listener* Subscriber();

protected:
  std::vector<Soldier*> units_;
  std::string fraction_;
  Hero* leader_ = 0;
};


class FrenchFactory : public AbstractFactory {
public:
  FrenchFactory();
  ~FrenchFactory();
};


class EnglishFactory : public AbstractFactory {
public:
  EnglishFactory();
  ~EnglishFactory();
};


class GermanFactory : public AbstractFactory {
public:
  GermanFactory();
  ~GermanFactory();
};


class FactoryCacher {
public:
  AbstractFactory* getFactory(const std::string& fraction);
  ~FactoryCacher();
private:
  FrenchFactory* french_factory_ = 0;
  EnglishFactory* english_factory_ = 0;
  GermanFactory* german_factory_ = 0;
};


AbstractFactory* getFactory (const std::string& fraction);

