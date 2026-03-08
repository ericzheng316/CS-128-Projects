#include "solution.hpp"

#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

std::vector<Item> LoadShoppingItemsFromFile(const std::string& filename) {
  std::vector<Item> shopping_items;
  std::ifstream ifs(filename);

  if (!ifs.is_open()) {
    throw std::runtime_error("The file cannot opened");
  }

  if (ifs.peek() == std::ifstream::traits_type::eof()) {
    return {};
  }
  Item temp_item;
  while (ifs.good()) {
    if (ifs.bad()) {
      return {};
    }
    ifs >> temp_item.item_name;
    if (ifs.fail()) {
      ifs.clear();
      ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    ifs >> temp_item.quantity;
    if (ifs.fail()) {
      ifs.clear();
      ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    ifs >> temp_item.price;
    if (ifs.fail()) {
      ifs.clear();
      ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    shopping_items.push_back(temp_item);
  }
  return shopping_items;
}