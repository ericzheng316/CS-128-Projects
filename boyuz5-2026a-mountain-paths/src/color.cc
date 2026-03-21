#include "color.hpp"

#include <stdexcept>
Color::Color(int r, int g, int b): red_(r), green_(g), blue_(b) {
  // need to ensure valid color has been constructed...
  if (r > kColorValueMax || r < kColorValueMin || g > kColorValueMax ||
      g < kColorValueMin || b > kColorValueMax || b < kColorValueMin) {
    throw std::invalid_argument("Invalid argument for color");
  }
}

// do not modify
bool operator==(const Color& rhs, const Color& lhs) {
  return (rhs.Red() == lhs.Red() && rhs.Green() == lhs.Green() &&
          rhs.Blue() == lhs.Blue());
}