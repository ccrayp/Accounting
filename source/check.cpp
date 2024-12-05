#include "check.h"

// Initialize checking
std::string check_cmd(std::string cmd) {
	std::stringstream ss(cmd);
	std::string temp;
	ss >> temp;
	if (temp == "help")
		return "";
	else if (temp == "clear")
		return "";
	else if (temp == "history")
		return "";
	else if (temp == "add")
		return add_check(cmd);
	else if (temp == "edit")
		return edit_check(cmd);
	else if (temp == "remove")
		return remove_check(cmd);
	else if (temp == "output")
		return output_check(cmd);

	return "Invalid syntaxis";
}

// Check add command
std::string add_check(std::string cmd) {
	std::stringstream ss(cmd);
	std::string arg;
	ss >> arg;

	arg.clear();
	ss >> arg;
	if (arg == "") return "Too few arguments";
	if (!(arg == "income" || arg == "outcome")) return "Invalid argument: " + arg;

	arg.clear();
	ss >> arg;
	if (arg == "") return "Too few arguments";
	try { std::stod(arg); }
	catch (...) { return "Invalid argument: " + arg; }

	arg.clear();
	ss >> arg;
	if (arg == "") return "Invalid argument: argument _mark_ is empty";
	else if(arg.size() > 100) return "Invalid argument: argument _mark_ must be less then 100 symbols";

	return "";
}

// Check edit commad
std::string edit_check(std::string cmd) {
	std::stringstream ss(cmd);
	std::string arg;
	ss >> arg;

	arg.clear();
	ss >> arg;
	if (arg == "") return "Too few arguments";
	try { std::stoi(arg); }
	catch (...) { return "Invalid argument: " + arg; }

	arg.clear();
	ss >> arg;
	if (arg == "") return "Too few arguments";
	if (!(arg == "income" || arg == "outcome")) return "Invalid argument: " + arg;

	arg.clear();
	ss >> arg;
	if (arg == "") return "Too few arguments";
	try { std::stod(arg); }
	catch (...) { return "Invalid argument: " + arg; }

	arg.clear();
	ss >> arg;
	if (arg == "") return "Invalid argument: argument _mark_ is empty";
	else if (arg.size() > 100) return "Invalid argument: argument _mark_ must be less then 100 symbols";

	return "";
}

// Check remove command
std::string remove_check(std::string cmd) {
	std::stringstream ss(cmd);
	std::string arg;
	ss >> arg;

	arg.clear();
	ss >> arg;
	if (arg == "") return "Too few arguments";
	try { std::stoi(arg); }
	catch (...) { 
		if(arg != "all")
			return "Invalid argument: " + arg; 
	}

	return "";
}

// Check output command
std::string output_check(std::string cmd) {
	std::stringstream ss(cmd);
	std::string arg;
	ss >> arg;

	arg.clear();
	ss >> arg;
	if (arg == "") return "Too few arguments";
	try { std::stoi(arg); }
	catch (...) {
		if (arg != "all")
			return "Invalid argument: " + arg;
	}

	return "";
}