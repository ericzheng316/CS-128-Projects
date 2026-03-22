#ifndef TRACER_FRAME_HPP
#define TRACER_FRAME_HPP

#include <string>

struct TracerFrame {
  std::string function_name;
  int argument = 0;
};

#endif  // TRACER_FRAME_HPP
