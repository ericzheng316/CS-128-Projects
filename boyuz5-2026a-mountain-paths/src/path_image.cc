#include "path_image.hpp"

#include <fstream>
#include <iostream>

#include "elevation_dataset.hpp"
#include "grayscale_image.hpp"
PathImage::PathImage(const GrayscaleImage& image,
                     const ElevationDataset& dataset) {
  width_ = image.Width();
  height_ = image.Height();
  paths_ = CalculatePaths(dataset);
  path_image_ = CreatPathImage(image, paths_);
}

std::vector<Path> PathImage::CalculatePaths(const ElevationDataset& dataset) {
  const int kMaximum = 99999;
  Path default_path(width_, 0);
  std::vector<Path> paths;
  for (size_t i = 0; i < height_; ++i) {
    Path path(width_, i);
    size_t current_row = i;
    path.SetLoc(0, i);
    for (size_t j = 0; j < width_ - 1; ++j) {
      int current_data = dataset.GetData()[current_row][j];
      int up = kMaximum;
      int middle = kMaximum;
      int down = kMaximum;
      if (IsValid(current_row - 1, j + 1)) {
        up = dataset.DatumAt(current_row - 1, j + 1);
      }
      if (IsValid(current_row, j + 1)) {
        middle = dataset.DatumAt(current_row, j + 1);
      }
      if (IsValid(current_row + 1, j + 1)) {
        down = dataset.DatumAt(current_row + 1, j + 1);
      }
      int min_change = abs(current_data - middle);
      size_t next_row = current_row;
      if (abs(current_data - down) < min_change) {
        min_change = abs(current_data - down);
        next_row = current_row + 1;
      }
      if (abs(current_data - up) < min_change &&
          abs(current_data - up) < abs(current_data - down)) {
        min_change = abs(current_data - up);
        next_row = current_row - 1;
      }
      current_row = next_row;
      path.SetLoc(j + 1, current_row);
      path.IncEleChange(min_change);
    }
    paths.push_back(path);
  }
  return paths;
}

std::vector<std::vector<Color>> PathImage::CreatPathImage(
    const GrayscaleImage& image, const std::vector<Path>& paths) const {
  unsigned int min_change = paths.at(0).EleChange();
  size_t min_index = 0;
  const Color kGreen(31, 253, 13);
  const Color kRed(252, 25, 63);
  std::vector<std::vector<Color>> result(height_, std::vector<Color>(width_));
  for (size_t i = 0; i < height_; ++i) {
    for (size_t j = 0; j < width_; ++j) {
      result[i][j] = image.GetImage()[i][j];
    }
  }
  for (size_t i = 0; i < paths.size(); ++i) {
    if (paths[i].EleChange() < min_change) {
      min_change = paths[i].EleChange();
      min_index = i;
    }
  }
  for (size_t i = 0; i < paths.size(); ++i) {
    for (size_t j = 0; j < paths[i].Length(); ++j) {
      result[paths[i].GetPath().at(j)][j] = kRed;
    }
  }

  for (size_t i = 0; i < paths[min_index].Length(); ++i) {
    result[paths[min_index].GetPath().at(i)][i] = kGreen;
  }
  return result;
}

bool PathImage::IsValid(size_t row, size_t col) const {
  return row >= 0 && row < height_ && col >= 0 && col < width_;
}

size_t PathImage::Height() const { return height_; }

size_t PathImage::Width() const { return width_; }

unsigned int PathImage::MaxColorValue() const { return kMaxColorValue; }

const std::vector<Path>& PathImage::Paths() const { return paths_; }

const std::vector<std::vector<Color>>& PathImage::GetPathImage() const {
  return path_image_;
}

void PathImage::ToPpm(const std::string& name) const {
  std::ofstream ofs(name);

  if (ofs.is_open()) {
    std::cout << "ToPpm is running!" << std::endl;
    ofs << "P3\n";
    ofs << width_ << " " << height_ << "\n";
    ofs << kMaxColorValue << "\n";
    for (size_t i = 0; i < height_; ++i) {
      for (size_t j = 0; j < width_; ++j) {
        if (j == width_ - 1) {
          Color c = path_image_[i][j];
          ofs << c.Red() << " " << c.Green() << " " << c.Blue() << "\n";
          continue;
        }
        Color c = path_image_[i][j];
        ofs << c.Red() << " " << c.Green() << " " << c.Blue() << " ";
      }
    }
    ofs << "\n";
  }
  std::cout << "ToPpm finished!" << std::endl;
}
