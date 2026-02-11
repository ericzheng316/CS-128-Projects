#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

struct Student {
  std::string full_name;
  unsigned int uin = 0;
  double gpa = 0.0;
};

#endif