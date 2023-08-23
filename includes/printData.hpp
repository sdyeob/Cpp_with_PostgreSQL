# ifndef PRINTDATA_HPP
# define PRINTDATA_HPP

#include <iostream>
#include <pqxx/pqxx>

void	printResult(const pqxx::result& res);
void	printRow(const pqxx::row& row);

# endif
