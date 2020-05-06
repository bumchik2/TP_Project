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
  virtual Hero* Leader() = 0;

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


class FactoryCacher {
public:
  AbstractFactory* getFactory(const std::string& fraction);
private:
  FrenchFactory* french_factory_ = 0;
  EnglishFactory* english_factory_ = 0;
  GermanFactory* german_factory_ = 0;
};


AbstractFactory* getFactory (const std::string& fraction);
