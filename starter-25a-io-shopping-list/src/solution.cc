#include "solution.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

std::vector<Item> LoadShoppingItemsFromFile(const std::string& filename) {
  std::vector<Item> shopping_items;

  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    throw std::runtime_error("Cannot open the file");
  }

  if (ifs.peek() == std::ifstream::traits_type::eof()) {
    throw std::invalid_argument("The file is empty");
  }

  Item temp_item;

  while (true) {
    ifs >> temp_item.item_name;

    if (ifs.eof()) {
      break;
    }

    if (ifs.fail()) {
      throw std::runtime_error("Format error: Failed to read");
    }

    ifs >> temp_item.quantity;
    if (ifs.fail()) {
      throw std::runtime_error("Format error: Failed to read int");
    }

    ifs >> temp_item.price;
    if (ifs.fail()) {
      throw std::runtime_error("Format error: Failed to read double");
    }

    shopping_items.push_back(temp_item);
  }

  return shopping_items;
}