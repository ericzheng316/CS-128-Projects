#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>

#include "helper.hpp"
#include "log.hpp"

std::vector<Log> Parse(const std::string& input_file);

std::vector<Log> Filter(const std::vector<Log>& logs);

std::string Diagnose(const std::vector<Log>& logs);

#endif  // SOLUTION_HPP
