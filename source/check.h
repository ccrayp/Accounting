#pragma once

#include <sstream>

// Initialize checking
std::string check_cmd(std::string cmd);

// Check add commad
std::string add_check(std::string cmd);

// Check edit commad
std::string edit_check(std::string cmd);

// Check remove command
std::string remove_check(std::string cmd);

// Check output command
std::string output_check(std::string cmd);