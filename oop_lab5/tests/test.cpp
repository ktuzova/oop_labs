#include <gtest/gtest.h>
#include "../include/Node.hpp"
#include "../include/List.hpp"
#include "../include/Allocator.hpp"

TEST(list_test, default_constructor) {
    List<int, Allocator<Node<int>>> a{};
    ASSERT_TRUE(a.size() == 0);
}

TEST(list_test, list_init_constructor) {
    List<int, Allocator<Node<int>>> a{1, 2, 3, 4};
    ASSERT_TRUE(a.size() == 4);
}

TEST(list_test, test_push_front) {
    List<int, Allocator<Node<int>>> a;
    a.push_front(-16);
    ASSERT_TRUE(a.size() == 1);
    ASSERT_TRUE(a.front() == -16);
    a.push_front(23492);
    ASSERT_TRUE(a.size() == 2);
    ASSERT_TRUE(a.front() == 23492);
}

TEST(list_test, test_push_back) {
    List<int, Allocator<Node<int>>> a;
    a.push_back(-16);
    ASSERT_TRUE(a.size() == 1);
    ASSERT_TRUE(a.front() == -16);
    a.push_back(23492);
    ASSERT_TRUE(a.size() == 2);
    ASSERT_TRUE((++a.begin()).get_node()->data == 23492);
}

TEST(list_test, test_clear) {
    List<int, Allocator<Node<int>>> a{1239, 9582, 28523};
    List<int, Allocator<Node<int>>> b;
    b.push_front(28523);
    b.push_front(9582);
    b.push_front(1239);
    ASSERT_TRUE(a.size() == 3 && (a == b));
    a.clear();
    ASSERT_TRUE(a.size() == 0);
}


TEST(list_test, test_front) {
    List<int, Allocator<Node<int>>> b{};

    b.push_back(28523);
    ASSERT_TRUE(b.size() == 1 && b.front() == 28523);
    b.push_front(-4532);
    ASSERT_TRUE(b.size() == 2 && b.front() == -4532);
}

TEST(list_test, test_begin_iter) {
    List<int, Allocator<Node<int>>> b{};

    b.push_front(28523);
    ASSERT_TRUE(b.size() == 1 && b.begin().get_node()->data == 28523);
    b.push_back(-4532);
    ASSERT_TRUE(b.size() == 2 && b.begin().get_node()->data == 28523);
}

TEST(list_test, test_end_iter) {
    List<int, Allocator<Node<int>>> b{};

    b.push_front(28523);
    ASSERT_TRUE(b.end() == Iterator<int>(nullptr, 1));
}

TEST(list_test, test_empty) {
    List<int, Allocator<Node<int>>> b{};

    ASSERT_TRUE(b.empty());
    b.push_front(28523);
    ASSERT_FALSE(b.empty());
}

TEST(list_test, test_erase) {
    List<int, Allocator<Node<int>>> b{459, 23, 8912, 3, 4, 1};
    ASSERT_TRUE(b.size() == 6);
    b.erase(b.begin());
    List<int, Allocator<Node<int>>> a{23, 8912, 3, 4, 1};
    ASSERT_TRUE(b.size() == 5 && a == b);

}

TEST(list_test, test_insert) {
    List<int, Allocator<Node<int>>> b{1, 0, 2};
    ASSERT_TRUE(b.size() == 3);
    b.insert(++b.begin(), 8);
    List<int, Allocator<Node<int>>> a{1, 8, 0, 2};
    ASSERT_TRUE(a == b);
}

TEST(list_test, test_insert_2) {
    List<int, Allocator<Node<int>>> b{1, 0, 2};
    ASSERT_TRUE(b.size() == 3);
    List<int, Allocator<Node<int>>> a{1, 8, 0, 2};
    b.insert(b.begin(), a.begin(), ++a.begin());
    List<int, Allocator<Node<int>>> c{1, 1, 0, 2};
    ASSERT_TRUE(b == c);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
