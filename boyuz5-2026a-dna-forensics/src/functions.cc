#include "functions.hpp"

#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>

std::string ProfileDNA(const std::string& dna_database,
                       const std::string& dna_sequence) {
  std::cout << "Input dna_database : " << dna_database << std::endl;
  std::cout << "Input dna_sequence : " << dna_sequence << std::endl;

  // write your implementation here... we strongly encourage that you leverage
  // additional functions to define this behavior.

  // Step 1 : read and process the data.
  std::vector<std::string> dna_database_vec = ReadDatabase(dna_database);
  std::string headline = dna_database_vec.at(0);
  std::vector<std::string> headline_vec = utilities::GetSubstrs(headline, ',');
  std::map<std::string, std::vector<int>> dna_database_map =
      ReadDatabaseToMap(dna_database_vec);

  // Step 2: analyze the dna_sequence
  std::vector<int> ana_dna_sequence =
      AnalyzeDNASequence(dna_sequence, headline_vec);
  PrintAnalyzeDNASequence(ana_dna_sequence);

  // Step 3: compare the featrue
  std::string profile;
  int match_times = 0;

  for (const auto& item : dna_database_map) {
    if (item.second == ana_dna_sequence) {
      profile = item.first;
      match_times++;
    }
  }
  if (profile.empty() || match_times > 1) {
    return "No match";
  }
  return profile;
}
/**
 * @param: file_name.
 *
 * @return: vector contains database.
 */
std::vector<std::string> ReadDatabase(const std::string& file_name) {
  std::vector<std::string> dna_database;
  std::ifstream ifs{file_name};
  for (std::string line; std::getline(ifs, line); line = "") {
    dna_database.push_back(line);
  }
  return dna_database;
}

/**
 * @param: A vector contains dna database
 * @return: A map, with key: name; with value: dna subsequence that repeted
 * times;
 */
std::map<std::string, std::vector<int>> ReadDatabaseToMap(
    const std::vector<std::string>& dna_database_vec) {
  std::map<std::string, std::vector<int>> result;

  for (size_t i = 1; i < dna_database_vec.size(); ++i) {
    std::vector<std::string> data_line =
        utilities::GetSubstrs(dna_database_vec.at(i), ',');
    std::string name = data_line.at(0);
    std::vector<int> subseq_times;
    for (size_t j = 1; j < data_line.size(); ++j) {
      std::string info = data_line.at(j);
      try {
        int times = std::stoi(info);
        subseq_times.push_back(times);
      } catch (std::invalid_argument& e) {
        throw;
      } catch (std::out_of_range& e) {
        throw;
      }
    }
    result.insert(std::make_pair(name, subseq_times));
  }
  return result;
}

std::vector<int> AnalyzeDNASequence(
    const std::string& dna_sequence,
    const std::vector<std::string>& headline_vec) {
  std::vector<int> ana_dna_sequence;
  for (size_t i = 1; i < headline_vec.size(); ++i) {
    std::string target = headline_vec.at(i);
    int times = 0;
    times = FindKeyValueInDNASequence(dna_sequence, target);
    ana_dna_sequence.push_back(times);
  }
  return ana_dna_sequence;
}

void PrintAnalyzeDNASequence(const std::vector<int>& ana_dna_sequence) {
  for (const auto& item : ana_dna_sequence) {
    std::cout << item << "\n" << std::endl;
  }
}

int FindKeyValueInDNASequence(const std::string& dna_sequence,
                              const std::string& target) {
  int max_times = 0;
  for (size_t i = 0; i < dna_sequence.length(); ++i) {
    int times = 0;
    while (dna_sequence.substr(i, target.size()) == target) {
      times++;
      i += target.size();
    }
    if (times > max_times) {
      max_times = times;
    }
  }
  return max_times;
}
