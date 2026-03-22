CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes -Wall -Wextra -pedantic -Werror -Wno-unused-parameter -O0 -g -fsanitize=address

exec: bin/exec

bin/exec: ./src/call_stack.cc ./src/driver.cc ./includes/call_stack.hpp ./includes/call_stack_exception.hpp ./includes/tracer_frame.hpp
	$(CXX) $(CXX_FLAGS) ./src/call_stack.cc ./src/driver.cc -o $@

.DEFAULT_GOAL := exec
.PHONY: exec clean

clean:
	rm -rf bin/*