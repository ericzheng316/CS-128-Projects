#ifndef CALL_STACK_EXCEPTION_HPP
#define CALL_STACK_EXCEPTION_HPP

#include <exception>
#include <string>

class CallStackException : public std::exception {
public:
  explicit CallStackException(const std::string& message): message_(message) {}
  const char* what() const noexcept override { return message_.c_str(); }

private:
  std::string message_;
};

#endif  // CALL_STACK_EXCEPTION_HPP
