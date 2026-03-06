#ifndef LOG_HPP
#define LOG_HPP
#include <string>

struct Log {
  std::string timestamp;
  std::string component;
  std::string event;
  std::string caused_by;
};

#endif  // LOG_HPP