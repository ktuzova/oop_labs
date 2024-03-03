#include <gtest/gtest.h>
#include <cmath>
#include "../include/Point.hpp"
#include "../include/Pentagon.hpp"
#include "../include/Hexagon.hpp"
#include "../include/Octagon.hpp"

TEST(point_test, basic_test_set) {
    Point<double> p1(1, 2);
    Point<double> p2(3, 4);
    ASSERT_TRUE(fabs(p1.dist(p2) - (2 * sqrt(2))) < DBL_EPSILON);
    ASSERT_TRUE(fabs(Point<double>().dist(Point<double>())) < DBL_EPSILON);
}


// Tests for Hexagon<double>

TEST(hexagon_test, default_constructor) {
    ASSERT_NO_THROW(Hexagon<double>());
}

TEST(hexagon_test, point_constructor) {
    double R = 6;
    Point<double> p1 = Point<double>(R * std::cos(1 * 2 * M_PI / 6), R * std::sin(1 * 2 * M_PI / 6));
    Point<double> p2 = Point<double>(R * std::cos(2 * 2 * M_PI / 6), R * std::sin(2 * 2 * M_PI / 6));
    Point<double> p3 = Point<double>(R * std::cos(3 * 2 * M_PI / 6), R * std::sin(3 * 2 * M_PI / 6));
    Point<double> p4 = Point<double>(R * std::cos(4 * 2 * M_PI / 6), R * std::sin(4 * 2 * M_PI / 6));
    Point<double> p5 = Point<double>(R * std::cos(5 * 2 * M_PI / 6), R * std::sin(5 * 2 * M_PI / 6));
    Point<double> p6 = Point<double>(R * std::cos(6 * 2 * M_PI / 6), R * std::sin(6 * 2 * M_PI / 6));
    ASSERT_NO_THROW(Hexagon<double>(p1, p2, p3, p4, p5, p6));
    EXPECT_THROW(Hexagon<double>(Point<double>(-100.0, -100.0), p2, p3, p4, p5, p6), std::logic_error);
}

TEST(hexagon_test, side_constructor) {
    ASSERT_NO_THROW(Hexagon<double>(4));
    EXPECT_THROW(Hexagon<double>(-4), std::logic_error);
}

TEST(hexagon_test, equality) {
    double R = 6;
    Point<double> p1 = Point<double>(R * std::cos(1 * 2 * M_PI / 6), R * std::sin(1 * 2 * M_PI / 6));
    Point<double> p2 = Point<double>(R * std::cos(2 * 2 * M_PI / 6), R * std::sin(2 * 2 * M_PI / 6));
    Point<double> p3 = Point<double>(R * std::cos(3 * 2 * M_PI / 6), R * std::sin(3 * 2 * M_PI / 6));
    Point<double> p4 = Point<double>(R * std::cos(4 * 2 * M_PI / 6), R * std::sin(4 * 2 * M_PI / 6));
    Point<double> p5 = Point<double>(R * std::cos(5 * 2 * M_PI / 6), R * std::sin(5 * 2 * M_PI / 6));
    Point<double> p6 = Point<double>(R * std::cos(6 * 2 * M_PI / 6), R * std::sin(6 * 2 * M_PI / 6));
    Hexagon<double> h0(p1, p2, p3, p4, p5, p6);

    Hexagon<double> h1(p1, p2, p3, p4, p5, p6);
    Hexagon<double> h2(h1);
    Hexagon<double> h3(146);

    ASSERT_TRUE(h1 == h0);
    ASSERT_TRUE(h2 == h0);
    ASSERT_FALSE(h3 == h1);
}


TEST(hexagon_test, area_test) {
    Hexagon<double> h0(3);

    ASSERT_TRUE(fabs(h0.area() - (3 * 3 * 3 * sqrt(3) / 2)) <= FLT_EPSILON);
}

TEST(hexagon_test, double_test) {
    double R = 3;
    Point<double> p1 = Point<double>(R * std::cos(1 * 2 * M_PI / 6) + 2, R * std::sin(1 * 2 * M_PI / 6) + 2);
    Point<double> p2 = Point<double>(R * std::cos(2 * 2 * M_PI / 6) + 2, R * std::sin(2 * 2 * M_PI / 6) + 2);
    Point<double> p3 = Point<double>(R * std::cos(3 * 2 * M_PI / 6) + 2, R * std::sin(3 * 2 * M_PI / 6) + 2);
    Point<double> p4 = Point<double>(R * std::cos(4 * 2 * M_PI / 6) + 2, R * std::sin(4 * 2 * M_PI / 6) + 2);
    Point<double> p5 = Point<double>(R * std::cos(5 * 2 * M_PI / 6) + 2, R * std::sin(5 * 2 * M_PI / 6) + 2);
    Point<double> p6 = Point<double>(R * std::cos(6 * 2 * M_PI / 6) + 2, R * std::sin(6 * 2 * M_PI / 6) + 2);
    Hexagon<double> h0(p1, p2, p3, p4, p5, p6);

    ASSERT_TRUE(fabs(static_cast<double>(h0) - (3 * 3 * 3 * sqrt(3) / 2)) <= FLT_EPSILON);
}


TEST(hexagon_test, geom_center) {
    Hexagon<double> h0(3);

    double R = 6;
    Point<double> p1 = Point<double>(R * std::cos(1 * 2 * M_PI / 6) + 2, R * std::sin(1 * 2 * M_PI / 6) + 2);
    Point<double> p2 = Point<double>(R * std::cos(2 * 2 * M_PI / 6) + 2, R * std::sin(2 * 2 * M_PI / 6) + 2);
    Point<double> p3 = Point<double>(R * std::cos(3 * 2 * M_PI / 6) + 2, R * std::sin(3 * 2 * M_PI / 6) + 2);
    Point<double> p4 = Point<double>(R * std::cos(4 * 2 * M_PI / 6) + 2, R * std::sin(4 * 2 * M_PI / 6) + 2);
    Point<double> p5 = Point<double>(R * std::cos(5 * 2 * M_PI / 6) + 2, R * std::sin(5 * 2 * M_PI / 6) + 2);
    Point<double> p6 = Point<double>(R * std::cos(6 * 2 * M_PI / 6) + 2, R * std::sin(6 * 2 * M_PI / 6) + 2);
    Hexagon<double> h1(p1, p2, p3, p4, p5, p6);

    ASSERT_TRUE(fabs(h0.geom_center().dist(Point<double>(0, 0))) <= FLT_EPSILON);
    ASSERT_TRUE(fabs(h1.geom_center().dist(Point<double>(2, 2))) <= FLT_EPSILON);
}

// Tests for Octagon<double>

TEST(octagon_test, default_constructor) {
    ASSERT_NO_THROW(Octagon<double>());
}

TEST(octagon_test, point_constructor) {
    double R = 10 / (2 * sin(M_PI / 8));
    Point<double> p1 = Point<double>(R * std::cos(1 * 2 * M_PI / 8), R * std::sin(1 * 2 * M_PI / 8));
    Point<double> p2 = Point<double>(R * std::cos(2 * 2 * M_PI / 8), R * std::sin(2 * 2 * M_PI / 8));
    Point<double> p3 = Point<double>(R * std::cos(3 * 2 * M_PI / 8), R * std::sin(3 * 2 * M_PI / 8));
    Point<double> p4 = Point<double>(R * std::cos(4 * 2 * M_PI / 8), R * std::sin(4 * 2 * M_PI / 8));
    Point<double> p5 = Point<double>(R * std::cos(5 * 2 * M_PI / 8), R * std::sin(5 * 2 * M_PI / 8));
    Point<double> p6 = Point<double>(R * std::cos(6 * 2 * M_PI / 8), R * std::sin(6 * 2 * M_PI / 8));
    Point<double> p7 = Point<double>(R * std::cos(7 * 2 * M_PI / 8), R * std::sin(7 * 2 * M_PI / 8));
    Point<double> p8 = Point<double>(R * std::cos(8 * 2 * M_PI / 8), R * std::sin(8 * 2 * M_PI / 8));

    ASSERT_NO_THROW(Octagon<double>(p1, p2, p3, p4, p5, p6, p7, p8));
    EXPECT_THROW(Octagon<double>(Point<double>(50.0, 50.0), p2, p3, p4, p5, p6, p7, p8), std::logic_error);
}

TEST(octagon_test, side_constructor) {
    ASSERT_NO_THROW(Octagon<double>(8));
    EXPECT_THROW(Octagon<double>(-15), std::logic_error);
}

TEST(octagon_test, equality) {
    double R = 10 / (2 * sin(M_PI / 8));
    Point<double> p1 = Point<double>(R * std::cos(1 * 2 * M_PI / 8), R * std::sin(1 * 2 * M_PI / 8));
    Point<double> p2 = Point<double>(R * std::cos(2 * 2 * M_PI / 8), R * std::sin(2 * 2 * M_PI / 8));
    Point<double> p3 = Point<double>(R * std::cos(3 * 2 * M_PI / 8), R * std::sin(3 * 2 * M_PI / 8));
    Point<double> p4 = Point<double>(R * std::cos(4 * 2 * M_PI / 8), R * std::sin(4 * 2 * M_PI / 8));
    Point<double> p5 = Point<double>(R * std::cos(5 * 2 * M_PI / 8), R * std::sin(5 * 2 * M_PI / 8));
    Point<double> p6 = Point<double>(R * std::cos(6 * 2 * M_PI / 8), R * std::sin(6 * 2 * M_PI / 8));
    Point<double> p7 = Point<double>(R * std::cos(7 * 2 * M_PI / 8), R * std::sin(7 * 2 * M_PI / 8));
    Point<double> p8 = Point<double>(R * std::cos(8 * 2 * M_PI / 8), R * std::sin(8 * 2 * M_PI / 8));
    Octagon<double> o0(p1, p2, p3, p4, p5, p6, p7, p8);

    Octagon<double> o1(p1, p2, p3, p4, p5, p6, p7, p8);
    Octagon<double> o2(o1);
    Octagon<double> o3(123);

    ASSERT_TRUE(o1 == o0);
    ASSERT_TRUE(o2 == o0);
    ASSERT_FALSE(o3 == o1);
}


TEST(octagon_test, area_test) {
    Octagon<double> o0(3);

    ASSERT_TRUE(fabs(o0.area() - (2 * 3 * 3 * (sqrt(2) + 1))) <= FLT_EPSILON);
}

TEST(octagon_test, double_test) {
    Octagon<double> o0(3);

    ASSERT_TRUE(fabs(static_cast<double>(o0) - (2 * 3 * 3 * (sqrt(2) + 1))) <= FLT_EPSILON);
}


TEST(octagon_test, geom_center) {
    Octagon<double> o0(3);

    double R = 6;
    Point<double> p1 = Point<double>(R * std::cos(1 * 2 * M_PI / 8) + 11, R * std::sin(1 * 2 * M_PI / 8) + 3);
    Point<double> p2 = Point<double>(R * std::cos(2 * 2 * M_PI / 8) + 11, R * std::sin(2 * 2 * M_PI / 8) + 3);
    Point<double> p3 = Point<double>(R * std::cos(3 * 2 * M_PI / 8) + 11, R * std::sin(3 * 2 * M_PI / 8) + 3);
    Point<double> p4 = Point<double>(R * std::cos(4 * 2 * M_PI / 8) + 11, R * std::sin(4 * 2 * M_PI / 8) + 3);
    Point<double> p5 = Point<double>(R * std::cos(5 * 2 * M_PI / 8) + 11, R * std::sin(5 * 2 * M_PI / 8) + 3);
    Point<double> p6 = Point<double>(R * std::cos(6 * 2 * M_PI / 8) + 11, R * std::sin(6 * 2 * M_PI / 8) + 3);
    Point<double> p7 = Point<double>(R * std::cos(7 * 2 * M_PI / 8) + 11, R * std::sin(7 * 2 * M_PI / 8) + 3);
    Point<double> p8 = Point<double>(R * std::cos(8 * 2 * M_PI / 8) + 11, R * std::sin(8 * 2 * M_PI / 8) + 3);
    Octagon<double> o1(p1, p2, p3, p4, p5, p6, p7, p8);

    ASSERT_TRUE(fabs(o0.geom_center().dist(Point<double>(0, 0))) <= FLT_EPSILON);
    ASSERT_TRUE(fabs(o1.geom_center().dist(Point<double>(11, 3))) <= FLT_EPSILON);
}


// Tests for Pentagon<double>

TEST(pentagon_test, default_constructor) {
    ASSERT_NO_THROW(Pentagon<double>());
}

TEST(pentagon_test, point_constructor) {
    double R = 6;
    Point<double> p1 = Point<double>(R * std::cos(1 * 2 * M_PI / 5), R * std::sin(1 * 2 * M_PI / 5));
    Point<double> p2 = Point<double>(R * std::cos(2 * 2 * M_PI / 5), R * std::sin(2 * 2 * M_PI / 5));
    Point<double> p3 = Point<double>(R * std::cos(3 * 2 * M_PI / 5), R * std::sin(3 * 2 * M_PI / 5));
    Point<double> p4 = Point<double>(R * std::cos(4 * 2 * M_PI / 5), R * std::sin(4 * 2 * M_PI / 5));
    Point<double> p5 = Point<double>(R * std::cos(5 * 2 * M_PI / 5), R * std::sin(5 * 2 * M_PI / 5));
    ASSERT_NO_THROW(Pentagon<double>(p1, p2, p3, p4, p5));
    EXPECT_THROW(Pentagon<double>(Point<double>(-100.0, -100.0), p2, p3, p4, p5), std::logic_error);
}

TEST(pentagon_test, side_constructor) {
    ASSERT_NO_THROW(Pentagon<double>(4));
    EXPECT_THROW(Pentagon<double>(-4), std::logic_error);
}

TEST(pentagon_test, equality) {
    double R = 6;
    Point<double> p1 = Point<double>(R * std::cos(1 * 2 * M_PI / 5), R * std::sin(1 * 2 * M_PI / 5));
    Point<double> p2 = Point<double>(R * std::cos(2 * 2 * M_PI / 5), R * std::sin(2 * 2 * M_PI / 5));
    Point<double> p3 = Point<double>(R * std::cos(3 * 2 * M_PI / 5), R * std::sin(3 * 2 * M_PI / 5));
    Point<double> p4 = Point<double>(R * std::cos(4 * 2 * M_PI / 5), R * std::sin(4 * 2 * M_PI / 5));
    Point<double> p5 = Point<double>(R * std::cos(5 * 2 * M_PI / 5), R * std::sin(5 * 2 * M_PI / 5));
    Pentagon<double> h0(p1, p2, p3, p4, p5);
    Pentagon<double> h1(p1, p2, p3, p4, p5);
    Pentagon<double> h2(h1);
    Pentagon<double> h3(146);
    ASSERT_TRUE(h1 == h0);
    ASSERT_TRUE(h2 == h0);
    ASSERT_FALSE(h3 == h1);
}

TEST(pentagon_test, area_test) {
    Pentagon<double> h0(3);
    ASSERT_TRUE(fabs(h0.area() - (0.25 * sqrt(5 + 2 * sqrt(5)) * 9)) <= FLT_EPSILON);
}


TEST(pentagon_test, double_test) {
    Pentagon<double> h0(3);

    ASSERT_TRUE(fabs(static_cast<double>(h0) - (3 * 3 * 0.25 * sqrt(5 + 2 * sqrt(5)))) <= FLT_EPSILON);
}

TEST(pentagonn_test, geom_center) {
    Pentagon<double> h0(3);

    double R = 6;
    Point<double> p1 = Point<double>(R * std::cos(1 * 2 * M_PI / 5) + 2, R * std::sin(1 * 2 * M_PI / 5) + 2);
    Point<double> p2 = Point<double>(R * std::cos(2 * 2 * M_PI / 5) + 2, R * std::sin(2 * 2 * M_PI / 5) + 2);
    Point<double> p3 = Point<double>(R * std::cos(3 * 2 * M_PI / 5) + 2, R * std::sin(3 * 2 * M_PI / 5) + 2);
    Point<double> p4 = Point<double>(R * std::cos(4 * 2 * M_PI / 5) + 2, R * std::sin(4 * 2 * M_PI / 5) + 2);
    Point<double> p5 = Point<double>(R * std::cos(5 * 2 * M_PI / 5) + 2, R * std::sin(5 * 2 * M_PI / 5) + 2);
    Pentagon<double> h1(p1, p2, p3, p4, p5);

    ASSERT_TRUE(fabs(h0.geom_center().dist(Point<double>(0, 0))) <= FLT_EPSILON);
    ASSERT_TRUE(fabs(h1.geom_center().dist(Point<double>(2, 2))) <= FLT_EPSILON);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}