#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>

#include "Record.h"
#include "console_color.h"

// 
void add(std::string cmd);

// 
void edit(std::string cmd);

// 
void save_edited(Record edited_record, size_t index);

// 
void remove_all();

// 
void remove_by_index(size_t index);

// 
void output_all();

// 
void output_by_index(size_t index);

// 
void save(std::string& cmd);