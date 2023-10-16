#include <gtest/gtest.h>
#include <vector>
#include "list.hpp"

using namespace std;

TEST(node, get_node)
{
    List<int> l = {1,2,3,4};
    EXPECT_EQ(l.node(1)->data, 2);
    EXPECT_EQ(l.node(1)->next->data, 3);

    EXPECT_THROW(l.node(4), const char*);
    EXPECT_THROW(l.node(-1), const char*);
}

TEST(find, get_node)
{
    List<int> l = {1,2,3,4,5};
    EXPECT_EQ(l.find(3)->data, 3);
    EXPECT_EQ(l.find(0), nullptr);
}

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

    EXPECT_THROW(l.insert(4, 33), const char*);
}

TEST(insert, edge_case)
{
    List<int> l = {};
    EXPECT_THROW(l.insert(1, 10), const char*);
    EXPECT_THROW(l.insert(0, 10), const char*);
}

TEST(popFront, edge_case)
{
    List<int> l;
    l.popFront();
    EXPECT_EQ(l, List<int>());

    l = {1,2};
    l.popFront();
    EXPECT_EQ(l, List<int>({2}));
    l.popFront();
    EXPECT_EQ(l, List<int>());
}

TEST(popBack, edge_case)
{
    List<int> l;
    l.popBack();
    EXPECT_EQ(l, List<int>());

}

TEST(remove, removing)
{
    List<int> l = {1,2,3,4,5};

    l.remove(0);
    EXPECT_EQ(l, List<int>({2,3,4,5}));
    l.remove(3);
    EXPECT_EQ(l, List<int>({2,3,4}));
    l.remove(1);
    EXPECT_EQ(l, List<int>({2,4}));
    l.remove(0);
    EXPECT_EQ(l, List<int>({4}));
    l.remove(0);
    EXPECT_EQ(l, List<int>({}));
}

TEST(remove, edge_case)
{
    List<int> l = {};
    EXPECT_THROW(l.remove(0), const char*);
}

TEST(clear, clear_all)
{
    List<int> l = {1,2,3,5,8};
    l.clear();
    EXPECT_EQ(l, List<int>());
}

TEST(operator_brackets, accessing)
{
    List<int> l = {1,2,3,4};
    EXPECT_EQ(l[0], 1);
    EXPECT_EQ(l[1], 2);
    EXPECT_EQ(l[2], 3);
    EXPECT_EQ(l[3], 4);

    List<int> l1 = {1,2,3,4,5};
    EXPECT_EQ(l1[0], 1);
    EXPECT_EQ(l1[1], 2);
    EXPECT_EQ(l1[2], 3);
    EXPECT_EQ(l1[3], 4);
    EXPECT_EQ(l1[4], 5);
}

TEST(operator_equal, equality) 
{
    List<int> l1 = {5,9,8,7,4};
    List<int> l2 = l1;
    EXPECT_EQ(l1, l2);

    l2 = {1,2};
    EXPECT_EQ(l2.size(), 2);
}