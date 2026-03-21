#include "path_image.hpp"

#include "elevation_dataset.hpp"
#include "grayscale_image.hpp"

PathImage::PathImage(const GrayscaleImage& image,
                     const ElevationDataset& dataset) {
  width_ = image.Width();
  height_ = image.Height();
}