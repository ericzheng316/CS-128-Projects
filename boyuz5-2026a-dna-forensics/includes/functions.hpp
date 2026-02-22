#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <map>
#include <string>
#include <vector>

#include "utilities.hpp"

std::string ProfileDNA(const std::string& dna_database,
                       const std::string& dna_sequence);

std::vector<std::string> ReadDatabase(const std::string& file_name);
std::map<std::string, std::vector<int>> ReadDatabaseToMap(
    const std::vector<std::string>& dna_database_vec);

std::vector<int> AnalyzeDNASequence(
    const std::string& dna_sequence,
    const std::vector<std::string>& headline_vec);

int FindKeyValueInDNASequence(const std::string& dna_sequence,
                              const std::string& target);

void PrintAnalyzeDNASequence(const std::vector<int>& ana_dna_sequence);

#endif