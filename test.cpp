#include "gtest/gtest.h"
#include "MergeSorter.h"
#include <vector>
#include <algorithm>

class MergeSortTest : public ::testing::Test {
protected:
    MergeSorter<int> sorterInt;
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