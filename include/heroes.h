#pragma once


#include "soldier.h"
#include "observer.h"

#include <string>


class Hero {
public:
  virtual ~Hero();
  Hero (const std::string& fraction, const std::string& name);
  virtual void speak () const = 0;
private:
  std::string fraction_;
  std::string name_;
};


class Napoleon : public Hero, public Listener {
public:
  Napoleon ();
  void getNotification(EventType event) override;
  void speak() const override;
};


class Elizabeth : public Hero, public Listener {
public:
  Elizabeth ();
  void getNotification(EventType event) override;
  void speak() const override;
};


class Bismarck : public Hero, public Listener {
public:
  Bismarck ();
  void getNotification(EventType event) override;
  void speak() const override;
};

