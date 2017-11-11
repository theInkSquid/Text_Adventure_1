#pragma once
#include <vector>
#include <iterator>
#include <algorithm>

#include "Item.hpp"

class Container: public Item {
public:
	using Contents = std::vector<ItemPtr> ;
	using iterator = Contents::iterator;
	using const_iterator = Contents::const_iterator;

	Container(std::string const & name, std::string const & desc)
	: Item{name, desc}
	{}


	void add(ItemPtr item) {
		contents_.push_back(std::move(item));
	}

	ItemPtr remove(Item * item) {
		auto iter = std::find_if(std::begin(contents_), std::end(contents_),
				[item](auto& elt) { return elt.get() == item; });
		if (iter == std::end(contents_)) {
			return {};
		}
		ItemPtr elt = std::move(*iter);
		contents_.erase(iter);
		return std::move(elt);
	}

	std::string getDescription() const override {
		std::string result = Item::getDescription();
		result += "  The " + getName() + " contains: ";
		Contents::size_type c = 0;
		for (auto& i : contents_) {
			result += (c++ ? (c == contents_.size() ? ", and " : ", ") : "") + i->getName();
		}
		if (contents_.size() == 0) {
			result += "nothing";
		}
		return result;
	}

	iterator begin() {
		return std::begin(contents_);
	}

	const_iterator cbegin() const {
		return std::cbegin(contents_);
	}

	iterator end() {
		return std::end(contents_);
	}

	const_iterator cend() const {
		return std::cend(contents_);
	}
private:
	Contents contents_;
};



