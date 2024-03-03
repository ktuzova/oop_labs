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

TEST(CheckTest, Суббота_57) {
    EXPECT_FALSE(checkPhobia("Суббота", 57));
}

TEST(CheckTest, Воскресенье_555) {
    EXPECT_FALSE(checkPhobia("Воскресенье", 555));
}

TEST(CheckTest, Вторник_90) {
    EXPECT_FALSE(checkPhobia("Вторник", 90));
}

TEST(CheckTest, Понедельник_10) {
    EXPECT_FALSE(checkPhobia("Понедельник", 10));
}

TEST(CheckTest, Среда_35) {
    EXPECT_FALSE(checkPhobia("Среда", 35));
}

TEST(CheckTest, Четверг_1) {
    EXPECT_FALSE(checkPhobia("Четверг", 1));
}

TEST(CheckTest, Пятница_21) {
    EXPECT_FALSE(checkPhobia("Пятница", 21));
}

TEST(CheckTest, Суббота_55) {
    EXPECT_FALSE(checkPhobia("Суббота", 55));
}

TEST(CheckTest, Воскресенье_667) {
    EXPECT_FALSE(checkPhobia("Воскресенье", 667));
}

TEST(CheckTest, Воскресенье_neg665) {
    EXPECT_FALSE(checkPhobia("Воскресенье", -665));
}

TEST(CheckTest, Понедельник_11) {
    EXPECT_FALSE(checkPhobia("Понедельник", 11));
}

TEST(CheckTest, Среда_33) {
    EXPECT_FALSE(checkPhobia("Среда", 33));
}

TEST(CheckTest, Четверг_5) {
    EXPECT_FALSE(checkPhobia("Четверг", 5));
}

TEST(CheckTest, Пятница_19) {
    EXPECT_FALSE(checkPhobia("Пятница", 19));
}

TEST(CheckTest, Суббота_54) {
    EXPECT_FALSE(checkPhobia("Суббота", 54));
}




int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
