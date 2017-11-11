#pragma once

#include "Item.hpp"
#include "Container.hpp"

class Room : public Item
{
public:
private:
  Container items_;
  std::map<Room*> exits_;
};
