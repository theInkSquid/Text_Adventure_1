/*
 * main.cpp
 *
 *  Created on: Oct 16, 2017
 *      Author: Brad
 */


#include <iostream>
#include "Item.hpp"
#include "Container.hpp"
#include "Weapon.hpp"

bool putIn(Item::ItemPtr& what, Item::ItemPtr& into) {
	if (auto * container = dynamic_cast<Container*>(into.get())) {
		container->add(std::move(what));
		return true;
	}
	return false;
}


int main() {
	std::cout << "Welcome to text_adventure_1! We hope you do well here.\n";

	Item::ItemPtr bag{new Container("bag", "A bag able to hold many things")};
	Item::ItemPtr machette{new Weapon("machette", "rusty machette", 1)};

	std::cout << bag->getDescription() << "\n";
	std::cout << machette->getDescription() << "\n";


	if (putIn(machette, bag)) {
		std::cout << "It was put into the bag" << std::endl;
	}

	std::cout << bag->getDescription() << "\n";
	if (machette) {
		std::cout << "What the heck?\n";
	}
	//std::cout << machette->getDescription() << "\n";

}
