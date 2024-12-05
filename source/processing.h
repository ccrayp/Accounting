#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "data.h"
#include "check.h"
#include "Record.h"
#include "console_color.h"

// 
void processing(std::string cmd);

// 
void print_cmd(std::string cmd);

// 
void remove_cmd(std::string cmd);

// 
void output_cmd(std::string cmd);

// 
void switch_cmd(std::string cmd);

// 
void print_help();