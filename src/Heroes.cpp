#include "heroes.h"
#include <string>
#include <iostream>


Hero::Hero (const std::string& fraction, const std::string& name) :
		fraction_(fraction), name_(name) { }


Hero::~Hero () { }


Napoleon::Napoleon() : Hero ("France", "Napoleon") { }

void Napoleon::Speak() const {
	std::cout << "Qui ne sait pas parler ne fera pas carriere!" << std::endl;
}


Elizabeth::Elizabeth() : Hero ("England", "Elizabeth") { }

void Elizabeth::Speak() const {
	std::cout << "God forgive You – but I can never." << std::endl;
}


Bismarck::Bismarck() : Hero ("Germany", "Bismarck") { }

void Bismarck::Speak() const {
	std::cout << "Politik ist die Kunst des moglichen!" << std::endl;
}

