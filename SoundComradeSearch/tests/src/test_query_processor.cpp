#include "../../include/query_processor.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::AtLeast;
using ::testing::_;

using std::make_pair, std::string, std::vector;

TEST(QuaryCategoryProcessorTest, ValidStrings) {
    AbstractProcessor processor;
    std::map <int, int> users;
    users.insert(make_pair(1, 1));
    users.insert(make_pair(2, 2));
    users.insert(make_pair(3, 3));

    UserCategoryRequest user_request = 
    make_pair(string("genre"), vector{string("rock"), string("pop"), string("jazz")});

    CategoryQuary category_quary = 
    std::vector{make_pair(1, vector{string("rock"),}),
                make_pair(2, vector{string("rock"), string("jazz")}),
                make_pair(3, vector{string("rap"),})};
    
    processor.ProceedCategoryQuary(user_request, category_quary, users);

    EXPECT_EQ(users.at(1), 2);
    EXPECT_EQ(users.at(2), 4);
    EXPECT_EQ(users.at(3), 3);
}