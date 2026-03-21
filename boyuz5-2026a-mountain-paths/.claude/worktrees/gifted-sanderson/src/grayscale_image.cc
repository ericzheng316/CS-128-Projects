#include "grayscale_image.hpp"

#include <cmath>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "color.hpp"
#include "elevation_dataset.hpp"
GrayscaleImage::GrayscaleImage(const ElevationDataset& dataset) {
  height_ = dataset.Height();
  width_ = dataset.Width();
  image_ = ReadDataToImage(dataset);
}

GrayscaleImage::GrayscaleImage(const std::string& filename,
                               size_t width,
                               size_t height) {
  ElevationDataset dataset(filename, width, height);
  height_ = height;
  width_ = width;
  image_ = ReadDataToImage(dataset);
}

std::vector<std::vector<Color>> GrayscaleImage::ReadDataToImage(
    const ElevationDataset& dataset) {
  Color default_color(0, 0, 0);
  std::vector<std::vector<Color>> image(
      dataset.Height(), std::vector<Color>(dataset.Width(), default_color));

  for (size_t i = 0; i < dataset.Height(); ++i) {
    for (size_t j = 0; j < dataset.Width(); ++j) {
      if (dataset.MaxEle() == dataset.MinEle()) {
        int shade_of_gray = 0;
        Color current(shade_of_gray, shade_of_gray, shade_of_gray);
        image[i][j] = current;
        continue;
      }
      int shade_of_gray = std::round(
          static_cast<double>(dataset.GetData()[i][j] - dataset.MinEle()) /
          (dataset.MaxEle() - dataset.MinEle()) * kMaxColorValue);
      Color current(shade_of_gray, shade_of_gray, shade_of_gray);
      image[i][j] = current;
    }
  }
  return image;
}

size_t GrayscaleImage::Width() const { return width_; }

size_t GrayscaleImage::Height() const { return height_; }

unsigned int GrayscaleImage::MaxColorValue() const { return kMaxColorValue; }

const Color& GrayscaleImage::ColorAt(int row, int col) const {
  return image_[row][col];
}

const std::vector<std::vector<Color>>& GrayscaleImage::GetImage() const {
  return image_;
}

void GrayscaleImage::ToPpm(const std::string& name) const {
  std::ofstream ofs(name);

  if (ofs.is_open()) {
    std::cout << "ToPpm is running!" << std::endl;
    ofs << "P3\n";
    ofs << width_ << " " << height_ << "\n";
    ofs << kMaxColorValue << "\n";
    for (size_t i = 0; i < height_; ++i) {
      for (size_t j = 0; j < width_; ++j) {
        if (j == width_ - 1) {
          Color c = image_[i][j];
          ofs << c.Red() << " " << c.Green() << " " << c.Blue() << "\n";
          continue;
        }
        Color c = image_[i][j];
        ofs << c.Red() << " " << c.Green() << " " << c.Blue() << " ";
      }
    }
    ofs << "\n";
  }
  std::cout << "ToPpm finished!" << std::endl;
}