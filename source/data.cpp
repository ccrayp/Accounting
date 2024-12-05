#include "data.h"

// 
void add(std::string cmd) {
	Record record;
	std::stringstream ss(cmd);
	std::string arg;
	ss >> arg;

	ss >> arg;
	if (arg == "income")
		record.is_income = true;
	else
		record.is_income = false;

	ss >> arg;
	record.sum = std::stod(arg);

	arg.clear();
	std::string temp;
	while (ss >> temp) {
		arg += temp + " ";
	}
	arg = arg.substr(0, arg.size() - 1);
	while (arg.size() < 100) {
		arg += '.';
	}
	strncpy(record.mark, arg.c_str(), sizeof(record.mark) - 1);
	record.mark[sizeof(record.mark) - 1] = '\0';

	std::ofstream out("data.dat", std::ios::binary | std::ios::app);
	out.write(reinterpret_cast<const char*>(&record), sizeof(record));
	out.close();
}

// 
void edit(std::string cmd) {
	Record record;
	std::stringstream ss(cmd);
	std::string arg;
	ss >> arg;

	ss >> arg;
	size_t index = std::stoi(arg);

	ss >> arg;
	if (arg == "income")
		record.is_income = true;
	else
		record.is_income = false;

	ss >> arg;
	record.sum = std::stod(arg);

	arg.clear();
	std::string temp;
	while (ss >> temp) {
		arg += temp + " ";
	}
	arg = arg.substr(0, arg.size() - 1);
	while (arg.size() < 100) {
		arg += '.';
	}
	strncpy(record.mark, arg.c_str(), sizeof(record.mark) - 1);
	record.mark[sizeof(record.mark) - 1] = '\0';
	
	save_edited(record, index);
}

void save_edited(Record edited_record, size_t index) {
	size_t counter = 1;
	std::ifstream in("data.dat", std::ios::binary);
	std::ofstream out("temp", std::ios::binary);
	Record record;
	bool edited = false;
	while (in.read(reinterpret_cast<char*>(&record), sizeof(record))) {
		if (counter == index) {
			out.write(reinterpret_cast<const char*>(&edited_record), sizeof(record));
			edited = true;
			counter++;
		}
		else {
			out.write(reinterpret_cast<const char*>(&record), sizeof(record));
			counter++;
		}
	}
	in.close();
	std::remove("data.dat");
	out.close();
	std::rename("temp", "data.dat");
	if (!edited) {
		std::cout << red << "There is not any record with such index\n" << reset;
	}
}

// 
void remove_all() {
	std::cout << "Are your sure to remove all records? y/n\n>> ";
	char ch;
	std::cin >> ch;
	std::cin.ignore();
	if (std::tolower(ch) == 'n')
		return;
	else if(std::tolower(ch) == 'y') {
		std::ofstream out("data.dat", std::ios::binary | std::ios::trunc);
		out.close();
	}
	else {
		std::cout << red << "Invalid argument: " + ch << reset << '\n';
	}
}

// 
void remove_by_index(size_t index) {
	std::cout << "Are your sure to remove all records? y/n\n>> ";
	char ch;
	std::cin >> ch;
	std::cin.ignore();
	if (std::tolower(ch) == 'n')
		return;
	else if (std::tolower(ch) == 'y') {
		Record record;
		size_t counter = 1, k = 1;
		std::ifstream in("data.dat", std::ios::binary);
		std::ofstream out("temp", std::ios::binary);
		while (in.read(reinterpret_cast<char*>(&record), sizeof(record))) {
			if (counter != index) {
				out.write(reinterpret_cast<const char*>(&record), sizeof(record));
				k++;
			}
			counter++;
		}
		in.close();
		std::remove("data.dat");
		out.close();
		std::rename("temp", "data.dat");
		if (k == counter) {
			std::cout << red << "There is not any record with such index\n" << reset;
		}
	}
	else {
		std::cout << red << "Invalid argument: " + ch << reset << '\n';
	}
}

// 
void output_all() {
	Record record;
	size_t counter = 1;
	long double sum = 0;
	std::ifstream in("data.dat", std::ios::binary);
	while (in.read(reinterpret_cast<char*>(&record), sizeof(record))) {
		if (record.is_income) {
			std::cout << green << counter << ". " << record.mark << " +" << record.sum << reset << "\n"; 
			sum += record.sum;
		}
		else {
			std::cout << red << counter << ". " << record.mark << " -" << record.sum << reset << "\n"; 
			sum -= record.sum;
		}
		counter++;
	}
	in.close();
	std::cout << "Total sum: " << sum << '\n';
}

// 
void output_by_index(size_t index) {
	Record record;
	size_t counter = 1;
	std::ifstream in("data.dat", std::ios::binary);
	while (in.read(reinterpret_cast<char*>(&record), sizeof(record))) {
		if (counter != index) {
			counter++;
			continue;
		}

		if (record.is_income)
			std::cout << green << counter << ". " << record.mark << " +" << record.sum << reset << "\n";
		else
			std::cout << red << counter << ". " << record.mark << " -" << record.sum << reset << "\n";
		counter = 0;
		break;
	}
	if (counter != 0) {
		std::cout << red << "There is not any record with such index\n" << reset;
	}
	in.close();
}