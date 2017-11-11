#pragma once
#include <memory>
#include <string>

class Item {
public:
  using ItemPtr = std::unique_ptr<Item>;

  Item(std::string const & name, std::string const & description)
    : name_{name}
    , description_ {description}
  {}

  virtual ~Item() = 0;

  virtual std::string getDescription() const {
    return description_;
  }

  std::string const & getName() const {
    return name_;
  }

private:
  std::string const name_;
  std::string const description_;
};

