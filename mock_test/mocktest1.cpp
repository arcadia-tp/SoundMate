#include <iostream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "UserActionFrame.h"

using ::testing::AtLeast;


class UserActionMock: public UserAction{
public:
    MOCK_METHOD1(createUser, UserData*());
    MOCK_METHOD2(changeMusicInstrument, void(UserData *User));
    MOCK_METHOD3(changeMusicGenre, void(UserData *User));
    MOCK_METHOD4(changeContactData, void(UserData *User));
    MOCK_METHOD5(createMessage, void(UserData *User1, UserData *User2));
};

TEST(MockGroupTests, CreateUserTest){
    UserActionMock *createmock = new UserActionMock();
    EXPECT_CALL(*createmock, createUser()).Times(AtLeast(1));
}

TEST(MockGroupTests, ChangeMusicInstrumentTest){
    UserActionMock *changemock = new UserActionMock();
    EXPECT_CALL(*changemock, changeMusicInstrument(User)).Times(AtLeast(1));
}

TEST(MockGroupTests, ChangeMusicGenreTest){
    UserActionMock *changemock = new UserActionMock();
    EXPECT_CALL(*changemock, changeMusicGenre(User)).Times(AtLeast(1));
}

TEST(MockGroupTests, ChangeContactDataTest){
    UserActionMock *changemock = new UserActionMock();
    EXPECT_CALL(*changemock, changeContactData(User)).Times(AtLeast(1));
}

TEST(MockGroupTests, CreateMessageTest){
    UserActionMock *createmock = new UserActionMock();
    EXPECT_CALL(*createmock, createMessage(User1, User2)).Times(AtLeast(1));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
