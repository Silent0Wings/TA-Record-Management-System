#pragma once
#include "General.h"
static std::string Current_Path;

// Load the file and parse it then convert it to vector of tas
void manual_Load(const std::string Path, std::vector <TA>& TA_vec);

// Build a string line by line from the vector of tas then save it in a file
void auto_Save(std::ofstream& outfile, const std::vector<TA>& TA_vec);

// Allows to input a path and check its existence before saving and parsing
void manual_Save(const std::vector<TA>& TA_vec);

// Separate a string by tabs into a vector of strings
std::vector<std::string> separate_String(const std::string& source);