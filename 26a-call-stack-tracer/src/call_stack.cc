#include "call_stack.hpp"

#include <exception>
void CallStack::Call(const std::string& function_name, int argument) {
  TracerFrame tf;
  tf.argument = argument;
  tf.function_name = function_name;
  frames_.push_back(tf);
}

void CallStack::Return() {
  if (frames_.empty()) {
    throw CallStackException("The stack is empty");
  }
  frames_.pop_back();
}

std::string CallStack::StackTrace() const {
  if (frames_.empty()) {
    return "Empty call stack";
  }
  std::string result;
  for (auto it = frames_.rbegin(); it != frames_.rend(); ++it) {
    result += it->function_name + "(";
    result += std::to_string(it->argument);
    if (it != frames_.rend() - 1) {
      result += ")\n";
    } else {
      result += ")";
    }
  }
  return result;
}

int CallStack::Depth() const { return frames_.size(); }

bool CallStack::IsEmpty() const { return frames_.empty(); }
