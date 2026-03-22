#include <iostream>

#include "call_stack.hpp"

int main() {
  CallStack stack;

  try {
    std::cout << "Simulating factorial(3)...\n\n";

    stack.Call("main", 0);
    stack.Call("factorial", 3);
    std::cout << stack.StackTrace() << "\n";

    stack.Call("factorial", 2);
    std::cout << stack.StackTrace() << "\n";

    stack.Call("factorial", 1);
    std::cout << "Peak depth: " << stack.Depth() << "\n";
    std::cout << stack.StackTrace() << "\n";

    std::cout << "Unwinding...\n\n";
    stack.Return();
    std::cout << stack.StackTrace() << "\n";

    stack.Return();
    std::cout << stack.StackTrace() << "\n";

    stack.Return();
    std::cout << stack.StackTrace() << "\n";

    stack.Return();
    std::cout << stack.StackTrace() << "\n";
  } catch (const CallStackException& e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

  return 0;
}
