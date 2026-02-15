#include "functions.hpp"

#include <iostream>
#include <set>
#include <stdexcept>

/**
 * TODO: Implement this function
 * @param word word to change to lowercase
 * @return result of changing every character in word to lowercase
 * DONE: Done.
 */
std::string StringToLower(const std::string& word) {
  std::cout << "Input to StringToLower() : " << word << std::endl;
  std::string result;
  for (unsigned int i = 0; i < word.size(); ++i) {
    result +=
        static_cast<char>(std::tolower(static_cast<unsigned char>(word[i])));
  }
  std::cout << result << std::endl;
  return result;
}

/**
 * TODO: Implement this function
 * @param v1 first character in potential vowel group
 * @param v2 second character in potential vowel group
 * @return true if v1 and v2 form a valid vowel group
 * DONE: Done.
 */
bool IsVowelGroup(const char& v1, const char& v2) {
  std::cout << "Input to IsVowelGroup() : \"" << v1 << "\" \"" << v2 << "\""
            << std::endl;

  std::set<std::string> vowel_group = {
      "ai", "ae", "ao", "au", "ei", "eu", "iu", "oi", "ou", "ui"};
  std::string check;
  check += v1;
  check += v2;
  return vowel_group.contains(check);
}

/**
 * TODO: Complete this function
 * @param v potential vowel character
 * @return true if v is a vowel
 * DONE: Done.
 */
bool IsVowel(const char& v) {
  std::cout << "Input to IsVowel() : \"" << v << "\"" << std::endl;
  const std::set<char> kVowel = {'a', 'e', 'i', 'o', 'u'};
  return kVowel.contains(v);
}

/**
 * TODO: Complete this function
 * @param c potential consonant character
 * @return true if c is a consonant
 * DONE: Done.
 */
bool IsConsonant(const char& c) {
  std::cout << "Input to IsConsonant() : \"" << c << "\"" << std::endl;
  const std::set<char> kConsonants = {'p', 'k', 'h', 'l', 'm', 'n', 'w'};
  return kConsonants.contains(c);
}

/**
 * TODO: Implement this function
 * @param c character to check validity of
 * @return true if input c is a valid character in the Hawaiian language, false
 * otherwise
 * DONE: Done.
 */
bool IsValidCharacter(const char& c) {
  std::cout << "Input to IsValidCharacter() : \"" << c << "\"" << std::endl;
  const std::set<char> kValidChar = {
      'a', 'e', 'i', 'o', 'u', 'p', 'k', 'h', 'l', 'm', 'n', 'w', ' ', '\''};
  return kValidChar.contains(c);
}

/**
 * TODO: Implement this function
 * @param word word to check validity of
 * @return true if every character in word is a valid character in the Hawaiian
 * language, false otherwise
 * DONE: Done.
 */
bool IsValidWord(const std::string& word) {
  std::cout << "Input to IsValidWord() : " << word << std::endl;
  for (char c : word) {
    if (!IsValidCharacter(c)) {
      return false;
    }
  }
  return true;
}

/**
 * TODO: Implement this function
 * @param c consonant to get pronunciation of
 * @param prev character before c, used for determining w translation
 *    set to null character as default if no value is passed in
 * @return pronunciation of the consonant c as a char
 * DONE: Done.
 */
char ConsonantPronunciation(const char& c, const char& prev) {
  std::cout << "Input to ConsonantPronunciation() : \"" << c << "\" \"" << prev
            << "\"" << std::endl;
  const std::set<char> kConsonants = {'p', 'k', 'h', 'l', 'm', 'n', 'w'};
  if (kConsonants.contains(c) && c != 'w') {
    return c;
  }
  if (prev == '\0' || prev == 'a' || prev == ' ') {
    return 'w';
  }
  if (prev == 'i' || prev == 'e') {
    return 'v';
  }
  if (prev == 'u' || prev == 'o') {
    return 'w';
  }
  return '\0';
}

/**
 * TODO: Implement this function
 * @param v1 first vowel in a vowel grouping
 * @param v2 second vowel in a vowel grouping
 * @return the pronunciation of the vowel grouping made up of v1 and v2
 * as a string
 * DONE: Done.
 */
std::string VowelGroupPronunciation(const char& v1, const char& v2) {
  std::cout << "Input to VowelGroupPronunciation() : \"" << v1 << "\" \"" << v2
            << "\"" << std::endl;
  std::set<std::string> vowel_group = {
      "ai", "ae", "ao", "au", "ei", "eu", "iu", "oi", "ou", "ui"};

  std::string vowel_g;
  vowel_g += v1;
  vowel_g += v2;
  if (vowel_g == "ai" || vowel_g == "ae") {
    return "eye";
  }
  if (vowel_g == "ao" || vowel_g == "au") {
    return "ow";
  }
  if (vowel_g == "ei") {
    return "ay";
  }
  if (vowel_g == "eu") {
    return "eh-oo";
  }
  if (vowel_g == "iu") {
    return "ew";
  }
  if (vowel_g == "oi") {
    return "oy";
  }
  if (vowel_g == "ou") {
    return "ow";
  }
  if (vowel_g == "ui") {
    return "ooey";
  }
  return "";
}

/**
 * TODO: Implement this function
 * @param v single vowel to get pronunciation of
 * @return the pronunciation of v as a string
 */
std::string SingleVowelPronunciation(const char& v) {
  std::cout << "Input to SingleVowelPronunciation() : \"" << v << "\""
            << std::endl;
  if (v == 'a') {
    return "ah";
  }
  if (v == 'e') {
    return "eh";
  }
  if (v == 'i') {
    return "ee";
  }
  if (v == 'o') {
    return "oh";
  }
  if (v == 'u') {
    return "oo";
  }
  return "";
}

/**
 * TODO: Implement this function
 * @param prev first character in set of three passed to function
 * @param curr second character in set of three passed to function
 * @param next third character in set of three passed to function
 * @return pronunciation of curr using next and prev as needed to determine
 * result
 * DONE: Done.
 */
std::string ProcessCharacter(const char& prev,
                             const char& curr,
                             const char& next) {
  std::cout << "Input to ProcessCharacter() : \"" << prev << "\" \"" << curr
            << "\" \"" << next << "\"" << std::endl;
  if (IsVowelGroup(curr, next)) {
    return VowelGroupPronunciation(curr, next);
  }
  if (IsVowel(curr)) {
    return SingleVowelPronunciation(curr);
  }
  if (IsConsonant(curr)) {
    std::string s;
    char c = ConsonantPronunciation(curr, prev);
    s.push_back(c);
    return s;
  }
  if (curr == ' ' || curr == '\'') {
    std::string s;
    s += curr;
    return s;
  }
  return "";
}

/**
 * TODO: Implement this function
 * @param word string to get pronunciation of
 * @return pronunciation of word
 * DONE: Done.
 */
std::string Pronunciation(const std::string& word) {
  std::cout << "Input to Pronunciation() : " << word << std::endl;
  std::string result;
  char prev = '\0';
  char curr = '\0';
  char next = '\0';
  for (unsigned int i = 0; i < word.size(); ++i) {
    curr = word[i];
    if (i != 0) {
      prev = word[i - 1];
    }
    if (i != word.size() - 1) {
      next = word[i + 1];
    } else {
      next = '\0';
    }
    if (IsVowelGroup(curr, next)) {
      result += ProcessCharacter(prev, curr, next);
      if (i != word.size() - 1 && next != ' ' && next != '\'' &&
          i != word.size() - 2) {
        result += "-";
      }
      ++i;
    } else if (IsVowel(curr)) {
      result += ProcessCharacter(prev, curr, next);
      if (i != word.size() - 1 && next != ' ' && next != '\'') {
        result += "-";
      }
    } else {
      result += ProcessCharacter(prev, curr, next);
    }
  }
  return result;
}

/**
 * TODO: Implement this function
 * @param hawaiian_word word to get pronunciation of
 * @return the pronunciation of hawaiian_word as a string if valid
 *  and throws an invalid_argument error if not valid
 *  DONE: Done.
 */
std::string GetPronunciation(const std::string& hawaiian_word) {
  std::cout << "Input to GetPronunciation() : " << hawaiian_word << std::endl;
  std::string lower_h = StringToLower(hawaiian_word);
  std::string result;
  if (IsValidWord(lower_h)) {
    result += Pronunciation(lower_h);
  } else {
    throw std::invalid_argument("There has invalid character in your input.");
  }
  return result;
}