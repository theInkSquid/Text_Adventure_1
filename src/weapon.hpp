#pragma once
#include "Item.hpp"

class Weapon : public Item {
public:
	Weapon(std::string const & name, std::string const & description, int attack)
	: Item {name, description}
	, attack_ {attack}
	{}

	std::string getDescription() const override {
		return "a +" + std::to_string(attack_) + " " + Item::getDescription();
	}

private:
	int attack_;
};
