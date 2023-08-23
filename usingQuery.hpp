# ifndef USINGQUERY_HPP
# define USINGQUERY_HPP

#include <iostream>
#include <pqxx/pqxx>

void			deleteQuery(pqxx::connection* connection_ptr, const std::string delete_sql);
void			insertQuery(pqxx::connection* connection_ptr, const std::string insert_sql);
pqxx::result	selectQuery(pqxx::connection* connection_ptr, const std::string select_sql);

# endif
