#include "solution.hpp"

#include <fstream>

Student ReadStudentRecFromStream(std::istream& is) {
  Student stu;
  // your implementation here...
  std::string first = "";
  std::string last = "";
  unsigned int uin = 0;
  double gpa = 0.0;
  char throwaway = '\0';

  is >> first;
  if (is.fail()) return Student{};

  is >> last;
  if (is.fail()) return Student{};

  if (last.empty() || last.back() != ',') return Student{};

  last.pop_back();

  is >> uin;
  if (is.fail()) return Student{};
  is >> throwaway;
  if (is.fail() || throwaway != ',') return Student{};

  is >> gpa;
  if (is.fail()) return Student{};

  stu.full_name = first + " " + last;
  stu.uin = uin;
  stu.gpa = gpa;

  return stu;
}