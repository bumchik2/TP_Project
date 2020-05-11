#include "heroes.h"
#include "observer.h"

#include <string>
#include <iostream>


Hero::Hero (const std::string& fraction, const std::string& name) :
    fraction_(fraction), name_(name) { }


Hero::~Hero () { }


Napoleon::Napoleon() : Hero ("France", "Napoleon") { }

void Napoleon::speak() const {
  std::cout << "Napoleon: Haw-haw-haw! Qui ne sait pas parler ne fera pas carriere!" << std::endl;
}

void Napoleon::getNotification(EventType event) {
  if (event == PlayerVictory || event == PlayerDefeat) {
    speak();
  }
}


Elizabeth::Elizabeth() : Hero ("England", "Elizabeth") { }

void Elizabeth::speak() const {
  std::cout << "Elizabeth: Ha-ha-ha! God forgive You – but I can never!" << std::endl;
}

void Elizabeth::getNotification(EventType event) {
  if (event == PlayerVictory || event == PlayerDefeat) {
    speak();
  }
}


Bismarck::Bismarck() : Hero ("Germany", "Bismarck") { }

void Bismarck::speak() const {
  std::cout << "Bismarck: Kha-kha-kha! Politik ist die Kunst des moglichen!" << std::endl;
}

void Bismarck::getNotification(EventType event) {
  if (event == PlayerVictory || event == PlayerDefeat) {
    speak();
  }
}

