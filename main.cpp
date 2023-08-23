#include <iostream>
#include <pqxx/pqxx>
#include "usingQuery.hpp"

# define PRINT_WIDTH 30

pqxx::connection* connectDB(const std::string& db_name) {
	pqxx::connection* connection_ptr = new pqxx::connection(db_name.c_str());
	if (connection_ptr->is_open()) {
		std::cout << "Connected to " << connection_ptr->dbname() << std::endl;
	} else {
		std::cout << "Connected is fail" << std::endl;
		return (nullptr);
	}
	return (connection_ptr);
}

void	printResult(const pqxx::result& r) {
	bool printHeader = true;
	for (auto row = r.begin(); row != r.end(); row++) {
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

int main(void) {
	try {
		const std::string insert_sql = "INSERT INTO public.myfirsttable (id, body) VALUES ('3', 'this is my first c++ with database')";
		const std::string select_sql = "SELECT * FROM public.myfirsttable WHERE body LIKE '%c++%' LIMIT 1";
		//const std::string delete_sql = "DELETE FROM public.myfirsttable WHERE id = 47";
		pqxx::connection *connection_ptr = connectDB("dbname=template1");
		if (connection_ptr == nullptr)
			return (1);
		insertQuery(connection_ptr, insert_sql);
		//deleteQuery(connection_ptr, delete_sql);
		pqxx::result R = selectQuery(connection_ptr, select_sql);

		printResult(R);
		connection_ptr->close();
		delete connection_ptr;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
