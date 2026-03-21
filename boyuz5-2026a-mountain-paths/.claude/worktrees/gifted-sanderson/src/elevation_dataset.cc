#include "elevation_dataset.hpp"

#include <fstream>
#include <iostream>
ElevationDataset::ElevationDataset(const std::string& filename,
                                   size_t width,
                                   size_t height) {
  width_ = width;
  height_ = height;

  data_ = std::vector<std::vector<int>>(height_, std::vector<int>(width_, 0));

  ReadFile(filename, data_);

  int max = data_[0][0];
  int min = data_[0][0];
  for (size_t i = 0; i < height_; ++i) {
    for (size_t j = 0; j < width_; ++j) {
      int current = data_[i][j];
      if (current > max) {
        max = current;
      }
      if (current < min) {
        min = current;
      }
    }
  }

  max_ele_ = max;
  min_ele_ = min;
}

void ElevationDataset::ReadFile(const std::string& filename,
                                std::vector<std::vector<int>>& data) const {
  std::ifstream ifs(filename);

  if (!ifs.is_open()) {
    throw std::invalid_argument("This file cannot be opened");
  }

  std::cout << "Reading file: " << filename << std::endl;

  for (size_t i = 0; i < height_; ++i) {
    for (size_t j = 0; j < width_; ++j) {
      if (!(ifs >> data[i][j])) {
        throw std::runtime_error("Data size is too small or invalid argument!");
        return;
      }
    }
  }

  int extra_element = 0;
  if (ifs >> extra_element) {
    throw std::runtime_error("There are too much elements in the file");
  }
}

size_t ElevationDataset::Width() const { return width_; }

size_t ElevationDataset::Height() const { return height_; }

int ElevationDataset::MaxEle() const { return max_ele_; }

int ElevationDataset::MinEle() const { return min_ele_; }

int ElevationDataset::DatumAt(size_t row, size_t col) const {
  return data_[row][col];
}

const std::vector<std::vector<int>>& ElevationDataset::GetData() const {
  return data_;
}
