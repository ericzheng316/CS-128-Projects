#ifndef CALL_STACK_HPP
#define CALL_STACK_HPP

#include <string>
#include <vector>

#include "call_stack_exception.hpp"
#include "tracer_frame.hpp"

class CallStack {
public:
  CallStack() = default;
  void Call(const std::string& function_name, int argument);
  void Return();
  std::string StackTrace() const;
  int Depth() const;
  bool IsEmpty() const;

private:
  std::vector<TracerFrame> frames_;
};

#endif  // CALL_STACK_HPP
