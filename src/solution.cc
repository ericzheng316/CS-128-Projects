#include "solution.hpp"

#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

CommentStats GenerateCommentStats(const std::vector<std::string>& comments) {
  CommentStats stats;
  std::map<std::string, int> mentioned;
  std::vector<std::string> popular;

  for (const auto& s : comments) {
    std::string words = "";
    bool capture = false;
    for (char c : s) {
      char lower_c = std::tolower(static_cast<unsigned char>(c));
      if (c == '@') {
        if (capture && words.length() > 1) {
          mentioned[words]++;
        }
        capture = true;
        words = "@";
        continue;
      }

      if (capture) {
        if (std::isalnum(static_cast<unsigned char>(c)) || c == '_') {
          words += lower_c;
        } else {
          if (words.length() > 1) {
            mentioned[words]++;
          }
          capture = false;
          words = "";
        }
      }
    }
    if (capture && words.length() > 1) {
      mentioned[words]++;
    }
  }

  for (const auto& [key, times] : mentioned) {
    if (times >= 2) {
      popular.push_back(key);
    }
  }
  stats.mention_frequencies = mentioned;
  stats.popular_mentions = popular;

  return stats;
}