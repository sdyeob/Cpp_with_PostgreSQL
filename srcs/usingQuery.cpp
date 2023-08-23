#include "usingQuery.hpp"

void	deleteQuery(pqxx::connection* connection_ptr, const std::string delete_sql) {
	pqxx::work W(*connection_ptr);
	/*
		pqxx::work is a transaction.
	*/
	W.exec(delete_sql);
	/*
		exec() is return pqxx::result, that is a two demension array consists of rows.
			and pqxx::result is work with pqxx::result::iterator and pqxx::row::iterator.c_str();
		and exec1() is return pqxx::row, that is just a row.
			and pqxx::result is work with pqxx::row::iterator.c_str();
	*/
	W.commit();
	/*
		if there is no commit(), the program has a error segmentation fault.
		the reason : ???
	*/
	std::cout << "Delete query is successfully done!" << std::endl;
}

void	insertQuery(pqxx::connection* connection_ptr, const std::string insert_sql) {
	pqxx::work W(*connection_ptr);
	W.exec(insert_sql);
	W.commit();
	std::cout << "Insert query is successfully done!" << std::endl;
}

pqxx::result	selectQuery(pqxx::connection* connection_ptr, const std::string select_sql) {
	pqxx::work W(*connection_ptr);
	pqxx::result R = W.exec(select_sql);
	W.commit();
	std::cout << "Select query is successfully done!" << std::endl;
	return (R);
}
