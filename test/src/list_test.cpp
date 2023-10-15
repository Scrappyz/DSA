#include <gtest/gtest.h>
#include <vector>
#include "list.hpp"

using namespace std;

TEST(append, appending)
{
    List<int> l;
    l.append(2);
    l.append(4);
    EXPECT_EQ(l, List<int>({2,4}));
}

TEST(append, connnected)
{
    List<int> l;
    l.append(1);
    l.append(2);
    l.append(3);
    EXPECT_EQ(l.head()->data, 1);
    EXPECT_EQ(l.head()->next->data, 2);
    EXPECT_EQ(l.head()->next->prev->data, 1);
}

TEST(prepend, connected)
{
    List<int> l;
    l.prepend(0);
    l.prepend(1);
    EXPECT_EQ(l.head()->data, 1);
    EXPECT_EQ(l.head()->next->data, 0);
    EXPECT_EQ(l.head()->next->prev->data, 1);
}

TEST(insert, inserting)
{
    List<int> l = {0,1};
    l.insert(0, 11);
    EXPECT_EQ(l, List<int>({11,0,1}));
    l.insert(2, 12);
    EXPECT_EQ(l, List<int>({11,0,12,1}));
}

TEST(insert, edge_case)
{
    List<int> l = {};
    EXPECT_THROW(l.insert(1, 10), const char*);
    EXPECT_THROW(l.insert(0, 10), const char*);
}

TEST(operator_brackets, accessing)
{
    List<int> l = {1,2,3,4};
    EXPECT_EQ(l[0], 1);
    EXPECT_EQ(l[1], 2);
    EXPECT_EQ(l[2], 3);
    EXPECT_EQ(l[3], 4);
}

TEST(operator_equal, equality) 
{
    List<int> l1 = {5,9,8,7,4};
    List<int> l2 = l1;
    EXPECT_EQ(l1, l2);
}