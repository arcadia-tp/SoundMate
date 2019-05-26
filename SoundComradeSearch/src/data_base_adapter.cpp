#include <boost/asio/ip/tcp.hpp>
#include <data_base_adapter.hpp>
#include <request.hpp>
#include <../../model_db/include/SearchData.h>

// std::string GetIdFromSearch(std::string search_string);//{};

typedef boost::asio::ip::tcp::socket BSocket;
typedef Request<std::map<int, int>> MapRequest;
typedef boost::asio::io_service BService;

template <>
DataBaseAdapter<BSocket, MapRequest, BService>::DataBaseAdapter(boost::asio::io_service &service,
                                   AbsDBParser *parser) : sock_(service), parser_(parser) {}



template <>
ResponseFromDB DataBaseAdapter<BSocket, MapRequest, BService>::GetResponse(const std::string &search_string) {
    ResponseFromDB response = parser_->Parse(GetIdFromSearch(search_string));
    return response;
}

template <>
DataBaseAdapter<BSocket, MapRequest, BService>::~DataBaseAdapter() {}