#include <data_base_query.hpp>

DataBaseQuery::DataBaseQuery() {}
DataBaseQuery::~DataBaseQuery() {}
ResponseFromDB &DataBaseQuery::GetResponse() {}
int DataBaseQuery::GetQuaryState() {}

DataBaseQueryStorage::DataBaseQueryStorage() {}
DataBaseQueryStorage::~DataBaseQueryStorage(){};

void DataBaseQueryStorage::AddCategory(Category &) {}
int DataBaseQueryStorage::GetQuaryState(const int) {}
Category &DataBaseQueryStorage::GetCategory() {}
ResponseFromDB &DataBaseQueryStorage::GetQuaryResponse(const int) {}
