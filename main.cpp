#include <iostream>
#include <pqxx/pqxx>
#include "usingQuery.hpp"
#include "printData.hpp"


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

int main(void) {
	try {
		pqxx::connection *connection_ptr = connectDB("dbname=template1");
		if (connection_ptr == nullptr) { return (1); }

		//const std::string insert_sql = "INSERT INTO public.myfirsttable (id, body) VALUES ('4', 'this is my first c++ with database')";
		const std::string select_sql = "SELECT * FROM public.myfirsttable WHERE body LIKE '%c++%' LIMIT 4";
		//const std::string delete_sql = "DELETE FROM public.myfirsttable WHERE id = 47";
		
		//insertQuery(connection_ptr, insert_sql);
		//deleteQuery(connection_ptr, delete_sql);

		printResult(selectQuery(connection_ptr, select_sql));
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
