#include "solution.hpp"

#include <fstream>
#include <map>
#include <set>
#include <stdexcept>

std::vector<Log> Parse(const std::string& input_file) {
  std::vector<Log> logs;
  std::ifstream ifs(input_file);

  if (!ifs.is_open()) {
    throw std::invalid_argument("This file is not opened sucessfully");
  }

  std::string dummy;
  std::getline(ifs, dummy);
  Log temp_log;
  while (ifs >> temp_log.timestamp >> temp_log.component >> temp_log.event >>
         temp_log.caused_by) {
    logs.push_back(temp_log);
  }

  return logs;
}

std::vector<Log> Filter(const std::vector<Log>& logs) {
  int longest_time = 0;
  int longest_index = 0;

  int current_time = 0;
  int current_index = 0;
  for (int i = 0; i < logs.size(); ++i) {
    if (logs.at(i).event != "SERVICE_UP") {
      if (current_time == 0) {
        current_index = i;
      }
      current_time++;
    } else {
      if (current_time >= longest_time) {
        longest_time = current_time;
        longest_index = current_index;
      }
      current_time = 0;
      current_index = 0;
    }
  }
  if (current_time > 0 && current_time >= longest_time) {
    longest_time = current_time;
    longest_index = current_index;
  }

  if (longest_time == 0) {
    return {};
  }
  std::vector<Log> filtered_logs =
      std::vector<Log>(logs.begin() + longest_index,
                       logs.begin() + longest_index + longest_time);
  return filtered_logs;
}

std::string Diagnose(const std::vector<Log>& logs) {
  std::string diagnose;
  DateTime start = ParseTimestamp(logs.at(0).timestamp);
  DateTime end = ParseTimestamp(logs.at(logs.size() - 1).timestamp);
  diagnose += "start : " + logs[0].timestamp + "\n";
  diagnose += "end: " + logs.at(logs.size() - 1).timestamp + "\n";
  diagnose += "time elapsed: " + std::to_string(end.day - start.day);
  diagnose += "d, " + std::to_string(end.hour - start.hour);
  diagnose += "h, " + std::to_string(end.minute - start.minute);
  diagnose += "m, " + std::to_string(end.second - start.second);
  diagnose += "s\n ";
  diagnose += "suspected root failure: " + logs.at(0).caused_by + "\n";
  diagnose += "recommendation: " + GetRecommendation(logs.at(0).caused_by);

  return diagnose;
}
