#include "printData.hpp"

# define PRINT_WIDTH 30

void	printResult(const pqxx::result& res) {
	bool printHeader = true;
	for (auto row = res.begin(); row != res.end(); row++) {
		if (printHeader) {
			for (auto field = row.begin(); field != row.end(); field++) {
					std::cout << std::setw(PRINT_WIDTH) << field->name() << '|';
			}
			std::cout << std::endl;
		}
		for (auto field = row.begin(); field != row.end(); field++) {
			std::cout << std::setw(PRINT_WIDTH) << field->c_str() << '|';
		}
		printHeader = false;
		std::cout << std::endl;
	}
}

void	printRow(const pqxx::row& row) {
	for (auto field = row.begin(); field != row.end(); field++)
		std::cout << field->name() << ": " << field->c_str() << "| ";
	std::cout << std::endl;
}
