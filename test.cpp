#include "gtest/gtest.h"
#include "MergeSorter.h"
#include <vector>
#include <algorithm>

class MergeSortTest : public ::testing::Test {
protected:
    MergeSorter<int> sorterInt;
    MergeSorter<double> sorterDouble;
};

TEST_F(MergeSortTest, AlreadySorted) {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST_F(MergeSortTest, ReverseSorted) {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST_F(MergeSortTest, RandomArray) {
    std::vector<int> arr = { 10, 2, 8, 5, 1, 9 };
    std::vector<int> expected = { 1, 2, 5, 8, 9, 10 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST_F(MergeSortTest, OnlyNegative) {
    std::vector<int> arr = { -5, -1, -10, -3 };
    std::vector<int> expected = { -10, -5, -3, -1 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST_F(MergeSortTest, MixedNegativeAndPositive) {
    std::vector<int> arr = { -5, 10, 0, -3, 2 };
    std::vector<int> expected = { -5, -3, 0, 2, 10 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST_F(MergeSortTest, EmptyArray) {
    std::vector<int> arr = {};
    EXPECT_NO_THROW(sorterInt.sort(arr));
    EXPECT_TRUE(arr.empty());
}

TEST_F(MergeSortTest, SingleElement) {
    std::vector<int> arr = { 42 };
    std::vector<int> expected = { 42 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST_F(MergeSortTest, Duplicates) {
    std::vector<int> arr = { 3, 1, 3, 2, 1 };
    std::vector<int> expected = { 1, 1, 2, 3, 3 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST_F(MergeSortTest, LargeArray) {
    std::vector<int> arr;
    for (int i = 0; i < 200; ++i) arr.push_back((i % 20) - 10);
    sorterInt.sort(arr);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
}