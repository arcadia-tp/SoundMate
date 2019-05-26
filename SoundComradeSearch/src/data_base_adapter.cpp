#include <data_base_adapter.hpp>
#include <request.hpp>

// #include <../../model_db/include/SearchData.h>

std::string GetIdFromSearch(std::string search_string);

typedef Request<std::map<int, int>> MapRequest;

template <>
DataBaseAdapter<MapRequest>::DataBaseAdapter(boost::asio::io_service &service,
                                   AbsDBParser *parser) : sock_(service), parser_(parser) {}



template <>
ResponseFromDB DataBaseAdapter<MapRequest>::GetResponse(const std::string &search_string) {
    ResponseFromDB response = parser_->Parse(GetIdFromSearch(search_string));
    return response;
}

template <>
DataBaseAdapter<MapRequest>::~DataBaseAdapter() { }