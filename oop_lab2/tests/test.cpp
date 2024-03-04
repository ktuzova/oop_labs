#include <gtest/gtest.h>
#include "../include/Seven.hpp"

TEST(test_operation_plus, basic_test_set) {
    Seven x1("123");
    x1 += x1;
    ASSERT_TRUE(x1 == Seven("246"));

    Seven x2("413654315");
    x2 += Seven("34234");
    ASSERT_TRUE(x2 == Seven("414021552"));

    Seven x3("6531232");
    ASSERT_TRUE((x3 + Seven("1000")) == Seven("6532232"));

    Seven x4("1666666");
    ASSERT_TRUE((x4 + Seven("6666666")) == Seven("11666665"));
}

TEST(test_operation_minus, basic_test_set) {
    Seven x1("123");
    x1 -= Seven("23");
    ASSERT_TRUE(x1 == Seven("100"));

    Seven x2("413654315");
    x2 -= Seven("34234");
    ASSERT_TRUE(x2 == Seven("413620051"));

    Seven x3("6531232");
    ASSERT_TRUE((x3 - Seven("1000")) == Seven("6530232"));

    Seven x4("1666666");
    ASSERT_TRUE((x4 - Seven("1666666")) == Seven("0"));
}

TEST(test_operator_greater, basic_test_set) {
    ASSERT_TRUE(Seven("123") > Seven("32"));

    ASSERT_TRUE(Seven("413620051") > Seven("352554"));

    ASSERT_FALSE(Seven("352554") > Seven("413620051"));

    ASSERT_FALSE(Seven("313620151") > Seven("413620051"));
}

TEST(test_operator_less, basic_test_set) {
    ASSERT_FALSE(Seven("123") < Seven("32"));

    ASSERT_FALSE(Seven("413620051") < Seven("352554"));

    ASSERT_TRUE(Seven("352554") < Seven("413620051"));

    ASSERT_TRUE(Seven("313620151") < Seven("413620051"));
}

TEST(test_operator_eq, basic_test_set) {
    ASSERT_TRUE(Seven("235234") == Seven("235234"));

    ASSERT_TRUE(Seven("0") == Seven("0"));

    ASSERT_FALSE(Seven("653242") == Seven("23421"));

    ASSERT_FALSE(Seven("653242") == Seven("553242"));
}

TEST(test_operator_not_eq, basic_test_set) {
    ASSERT_FALSE(Seven("235234") != Seven("235234"));

    ASSERT_FALSE(Seven("0") != Seven("0"));

    ASSERT_TRUE(Seven("653242") != Seven("23421"));

    ASSERT_TRUE(Seven("653242") != Seven("553242"));
}

TEST(test_shrink_to_fit, basic_test_set) {
    Seven x1("00123");
    ASSERT_TRUE(x1 == Seven("123"));

    Seven x2("0000");
    ASSERT_TRUE(x2 == Seven("0"));
}

TEST(test_constructors, basic_test_set) {
    Seven x1("123");
    Seven x2(x1);
    x2 -= Seven("3");

    ASSERT_TRUE(x2 == (x1 - Seven("3")));

    Seven x3("5432");
    Seven x4 = x3;
    x4 += Seven("1");

    ASSERT_TRUE(x4 == Seven("5433"));

    Seven x5({'5'});
    ASSERT_TRUE(x5 == Seven("5"));
}