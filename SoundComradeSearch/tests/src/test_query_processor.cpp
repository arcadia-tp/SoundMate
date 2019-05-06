#include "../../include/query_processor.hpp"
#include "../../src/query_processor.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::AtLeast;
using ::testing::_;

using std::make_pair, std::string, std::vector;

TEST(QuaryCategoryProcessorTest, ValidStrings) {
    AbstractProcessor<UsersMap> *processor = new QueryProcessor();
    UsersMap users_map;
    users_map.insert(make_pair(1, 1));
    users_map.insert(make_pair(2, 2));
    users_map.insert(make_pair(3, 3));

    Category category;
    category.category_name = "instrument";
    category.key_words.push_back("guitar");
    category.key_words.push_back("drum");

    std::vector<UserData> response_vector;
    UserData user_data1;
    user_data1.user_id = 1;
    user_data1.data_vector.push_back("guitar");
    user_data1.data_vector.push_back("balalaika");
    response_vector.push_back(user_data1);

    UserData user_data2;
    user_data2.user_id = 2;
    user_data2.data_vector.push_back("guitar");
    user_data2.data_vector.push_back("bagpipe");
    response_vector.push_back(user_data2);

    UserData user_data3;
    user_data3.user_id = 3;
    user_data3.data_vector.push_back("drum");
    user_data3.data_vector.push_back("guitar");
    response_vector.push_back(user_data3);
    
    processor->ProceedCategoryQuery(category, response_vector, users_map);

    EXPECT_EQ(users_map.at(1), 2);
    EXPECT_EQ(users_map.at(2), 3);
    EXPECT_EQ(users_map.at(3), 5);
}