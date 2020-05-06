#pragma once


#include "soldier.h"
#include <string>


class Hero {
public:
  virtual ~Hero();
  Hero (const std::string& fraction, const std::string& name);
  virtual void Speak () const = 0;
private:
  std::string fraction_;
  std::string name_;
};


class Napoleon : public Hero {
public:
  Napoleon ();
  void Speak() const override;
};


class Elizabeth : public Hero {
public:
  Elizabeth ();
  void Speak() const override;
};


class Bismarck : public Hero {
public:
  Bismarck ();
  void Speak() const override;
};

