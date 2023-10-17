#include <gtest/gtest.h>
#include "insertion_sort.hpp"

TEST(sort, sorting)
{
    std::vector<int> v = {5,4,3,2,1};
    insertionSort(v);
    EXPECT_EQ(v, std::vector<int>({1,2,3,4,5}));
    insertionSort(v, true);
    EXPECT_EQ(v, std::vector<int>({5,4,3,2,1}));

    v = {5,9,8,7,3,6,1,2};
    insertionSort(v);
    EXPECT_EQ(v, std::vector<int>({1,2,3,5,6,7,8,9}));
    insertionSort(v, true);
    EXPECT_EQ(v, std::vector<int>({9,8,7,6,5,3,2,1}));
}