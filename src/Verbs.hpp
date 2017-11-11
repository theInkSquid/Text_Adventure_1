#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <exception>

class Verbs {

public:
  using StringVec = std::vector<std::string>;
  using VerbFunc = std::function<bool(StringVec const&)>;

  VerbFunc* lookup(std::string const & verb) {
    if (auto iter = verbs_.find(verb); iter != verbs_.end()) {
      return *iter;
    }
    return nullptr;
  }
  
  void registerFunction(std::string const& verb, VerbFunc func) {
    if (lookup(verb)) {
      throw std::logic_error("Name already in use");
    }
    verbs_[verb] = func;
  }

private:
  using VerbMap = std::unordered_map<std::string, VerbFunc>;

  VerbMap verbs_;
};
