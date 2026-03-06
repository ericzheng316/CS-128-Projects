#include <chrono>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "solution.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "\tUsage: " << argv[0] << " <input_log_file>\n";
    return 1;
  }
  std::string input_file = argv[1];

  std::vector<Log> logs = Parse(input_file);
  if (logs.empty()) {
    std::cerr << "No logs were read from file: " << input_file << "\n";
    return 1;
  }

  std::vector<Log> filtered_logs = Filter(logs);
  if (filtered_logs.empty()) {
    std::cout << "No incidents occurred within the provided logs" << std::endl;
    return 0;
  }

  std::string diagnostic_report = Diagnose(filtered_logs);
  std::cout << diagnostic_report << "\n";
  return 0;
}
