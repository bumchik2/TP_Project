#pragma once


#include <string>


class Soldier {
public:
	Soldier(int health, int damage_min, int damage_max, const std::string& fraction, const std::string& type);
	virtual ~Soldier();

	void takeDamage (int damage);
	virtual void causeDamage (Soldier* enemy) const;
	bool isAlive() const;
	void Die();

	void printInfo() const;

protected:
	int health_;
	int damage_min_;
	int damage_max_;
	bool is_alive_ = true;

	std::string fraction_ = 0;
	std::string type_ = 0;
};

