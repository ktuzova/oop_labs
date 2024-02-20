#include "gtest/gtest.h"
#include "PhobiaTest.hpp"
TEST(CheckTest, Понедельник_12) {
    EXPECT_TRUE(checkPhobia("Понедельник", 12));
}

TEST(CheckTest, Вторник_101) {
    EXPECT_TRUE(checkPhobia("Вторник", 101));
}

TEST(CheckTest, Среда_34) {
    EXPECT_TRUE(checkPhobia("Среда", 34));
}

TEST(CheckTest, Четверг_0) {
    EXPECT_TRUE(checkPhobia("Четверг", 0));
}

TEST(CheckTest, Пятница_20) {
    EXPECT_TRUE(checkPhobia("Пятница", 20));
}

TEST(CheckTest, Суббота_56) {
    EXPECT_TRUE(checkPhobia("Суббота", 56));
}

TEST(CheckTest, Воскресенье_666) {
    EXPECT_TRUE(checkPhobia("Воскресенье", 666));
}

TEST(CheckTest, Воскресенье_neg666) {
    EXPECT_TRUE(checkPhobia("Воскресенье", -666));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
