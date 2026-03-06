#include "helper.hpp"

DateTime ParseTimestamp(const std::string& timestamp) {
  int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
  std::istringstream iss(timestamp);

  if (!(iss >> year) || iss.get() != '-' || !(iss >> month) ||
      iss.get() != '-' || !(iss >> day) || iss.get() != 'T' || !(iss >> hour) ||
      iss.get() != ':' || !(iss >> minute) || iss.get() != ':' ||
      !(iss >> second)) {
    throw std::invalid_argument(
        "Invalid timestamp format. Expected YYYY-MM-DDTHH:MM:SS");
  }

  if (month < 1 || month > MAX_MONTH || day < 1 || day > MAX_DAY || hour < 0 ||
      hour > MAX_HOUR || minute < 0 || minute > MAX_MINUTE || second < 0 ||
      second > MAX_SECOND) {
    throw std::invalid_argument("Timestamp values out of range.");
  }

  return {year, month, day, hour, minute, second};
}

std::string GetRecommendation(const std::string& suspected_cause) {
  if (suspected_cause == "db-service") {
    return "investigate database performance and connectivity. Restart is "
           "likely needed.";
  }
  if (suspected_cause == "api-gateway") {
    return "restart the api gateway and verify routing.";
  }
  if (suspected_cause == "disk-system") {
    return "check available disk "
           "space, I/O utilization, and hardware health.";
  }
  if (suspected_cause == "worker-pool") {
    return "increase the number of "
           "workers, reduce task load, or optimize task processing time.";
  }
  return "unrecognized root cause; no recommendations available.";
}