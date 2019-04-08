#include <data_base_query.hpp>

DataBaseQuery::DataBaseQuery() {}
DataBaseQuery::~DataBaseQuery() {}
ResponseFromDB &DataBaseQuery::GetResponse() {}
int DataBaseQuery::GetQuaryState() {}


DataBaseQueryStorage::DataBaseQueryStorage() {}
DataBaseQueryStorage::~DataBaseQueryStorage() {};

void DataBaseQueryStorage::AddQuery(CategoryQuery &) {}
int DataBaseQueryStorage::GetQuaryState(const int) {}
CategoryQuery &DataBaseQueryStorage::GetQuary() {}
ResponseFromDB &DataBaseQueryStorage::GetQuaryResponse(const int) {}
