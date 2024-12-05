#include "processing.h"

void processing(std::string cmd) {
	std::string check_res = check_cmd(cmd);
	if (check_res != "") {
		std::cout << red << check_res << '\n' << reset;
		save(cmd);
		return;
	}

	print_cmd(cmd);
	if (cmd != "history")
		save(cmd);

	if (cmd == "help") {
		print_help();
	}
	else if (cmd == "clear") {
		std::cout << "\033[2J\033[H";
		std::cout.flush();
	}
	else if (cmd == "history") {
		std::ifstream in("history.dat");
		std::string temp;
		while (getline(in, temp)) {
			std::cout << temp << '\n';
		}
	}
	else
		switch_cmd(cmd);
}

void switch_cmd(std::string cmd) {
	std::stringstream ss(cmd);
	std::string arg;
	ss >> arg;
	if (arg == "add")
		add(cmd);
	else if (arg == "edit")
		edit(cmd);
	else if (arg == "remove")
		remove_cmd(cmd);
	else if (arg == "output")
		output_cmd(cmd);
}

void remove_cmd(std::string cmd) {
	std::stringstream ss(cmd);
	std::string arg;
	ss >> arg >> arg;
	if (arg == "all")
		remove_all();
	else
		remove_by_index(std::stoi(arg));
}

void output_cmd(std::string cmd) {
	std::stringstream ss(cmd);
	std::string arg;
	ss >> arg >> arg;
	if (arg == "all")
		output_all();
	else
		output_by_index(std::stoi(arg));
}

void print_cmd(std::string cmd) {
	std::cout << "\033[F\033[K";
	std::cout << ">> " << magenta << cmd << reset << "\n";
}

void print_help() {
	std::cout << green << "Description of commands:\n"
		<< magenta << "add " << blue << "_mode_ _sum_ _mark_ " << reset << "- add new record with specified paremeters:\n  mode (income/outcome)\n  sum (value with point)\n  mark (description of record)\n"
		<< magenta << "edit " << blue << "_index_ _mode_ _sum_ _mark_ " << reset << "- edit a record with specified index\n"
		<< magenta << "remove " << blue << "_index_ " << reset << "- remove record by specified index\n"
		<< magenta << "remove " << blue << "all " << reset << "- remove all records\n"
		<< magenta << "output " << blue << "_index_ " << reset << "- output record by specified index\n"
		<< magenta << "output " << blue << "all " << reset << "- output all records\n"
		<< magenta << "history " << reset << "- output all entered commands\n"
		<< magenta << "clear " << reset << "- clear screen\n"
		<< magenta << "exit " << reset << "- close this application\n";
}

void save(std::string& cmd) {
	std::ifstream in("history.dat");
	std::ofstream out("temp.dat");
	
	std::vector<std::string> cmds;
	std::string temp = "";
	while (getline(in, temp)) {
		cmds.push_back(temp);
		temp.clear();
	}
	if(temp != "")
		cmds.push_back(temp);
	in.close();
	std::remove("history.dat");

	if (cmds.size() > 99) {
		for (int i = cmds.size() - 99; i < cmds.size(); i++) {
			out << cmds[i] + '\n';
		}
	}
	else {
		for (auto it : cmds) {
			out << it + '\n';
		}
	}
	out << cmd + "\n";
	out.close();
	std::rename("temp.dat", "history.dat");
}