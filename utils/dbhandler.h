#ifndef DBHANDLER_H
#define DBHANDLER_H

#include <string>
#include <nlohmann/json.hpp>
#include <boost/mysql.hpp>

class DatabaseHandler
{
private:
    nlohmann::json config;
    std::string host;
    std::string port;
    std::string user;
    std::string password;
    std::string database;
    boost::asio::io_context ctx;
    boost::asio::ssl::context ssl_ctx;
    boost::mysql::tcp_ssl_connection conn;
    boost::asio::ip::tcp::resolver resolver;
    boost::asio::ip::basic_resolver_results<boost::asio::ip::tcp> endpoints;
public:
    DatabaseHandler(const std::string& path = "../config/dbconfig.json");
    DatabaseHandler(const DatabaseHandler&) = delete;
    ~DatabaseHandler();
};



#endif
