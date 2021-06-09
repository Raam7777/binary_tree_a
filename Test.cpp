#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
using namespace std;

#include "BinaryTree.hpp"
using namespace ariel;

TEST_CASE("Test - tree of INT")
{
    BinaryTree<int> tree;

    CHECK_NOTHROW(tree.add_root(1));
    CHECK_NOTHROW(tree.add_root(5));
    CHECK_NOTHROW(tree.add_root(3));
    CHECK_NOTHROW(tree.add_root(1));
    CHECK_NOTHROW(tree.add_left(1, 20));  // Now 20 is the left child of 1
    CHECK_NOTHROW(tree.add_left(1, 9));   // Now 9 is the left child of 1
    CHECK_NOTHROW(tree.add_left(9, 16));  // Now 16 is the left child of 9
    CHECK_NOTHROW(tree.add_left(9, 4));   // Now 4 is the left child of 9
    CHECK_NOTHROW(tree.add_right(9, 34)); // Now 34 is the right child of 9
    CHECK_NOTHROW(tree.add_right(9, 5));  // Now 5 is the right child of 9
    CHECK_NOTHROW(tree.add_right(1, 31)); // Now 31 is the right child of 1
    CHECK_NOTHROW(tree.add_right(1, 3));  // Now 3 is the right child of 1
    CHECK_NOTHROW(tree.add_left(1, 54));
    CHECK_NOTHROW(tree.add_left(1, 2));

    CHECK_THROWS(tree.add_right(20, 3)); //the tree not contain Node with data 20
    CHECK_THROWS(tree.add_right(15, 1)); //the tree not contain Node with data 15
    CHECK_THROWS(tree.add_left(40, 3));  //the tree not contain Node with data 40
    CHECK_THROWS(tree.add_left(30, 3));  //the tree not contain Node with data 30
    CHECK_NOTHROW(cout << tree << endl);

    int pre[] = {1, 2, 4, 5, 3};
    int in[] = {4, 2, 5, 1, 3};
    int post[] = {4, 5, 2, 3, 1};

    int k = 0;
    for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it)
    {
        CHECK((*it) == pre[k]);
        k++;
    } // prtree: 1 2 4 5 3

    k = 0;
    for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it)
    {
        CHECK((*it) == in[k]);
        k++;
    } // prtree: 4 2 5 1 3

    k = 0;
    for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it)
    {
        CHECK((*it) == post[k]);
        k++;
    } // prtree: 4 5 2 3 1
}

TEST_CASE("Test - tree of CHAR")
{
    BinaryTree<int> chars;

    CHECK_NOTHROW(chars.add_root('a'));
    CHECK_NOTHROW(chars.add_root('e'));
    CHECK_NOTHROW(chars.add_root('c'));
    CHECK_NOTHROW(chars.add_root('a'));
    CHECK_NOTHROW(chars.add_left('a', 'v'));  // Now 20 is the left child of 1
    CHECK_NOTHROW(chars.add_left('a', 'x'));   // Now 9 is the left child of 1
    CHECK_NOTHROW(chars.add_left('q', 'z'));  // Now 16 is the left child of 9
    CHECK_NOTHROW(chars.add_left('q', 's'));   // Now 4 is the left child of 9
    CHECK_NOTHROW(chars.add_right('q', 's')); // Now 34 is the right child of 9
    CHECK_NOTHROW(chars.add_right('q', 'e'));  // Now 5 is the right child of 9
    CHECK_NOTHROW(chars.add_right('a', 'a')); // Now 31 is the right child of 1
    CHECK_NOTHROW(chars.add_right('a', 'c'));  // Now 3 is the right child of 1
    CHECK_NOTHROW(chars.add_left('a', 'd'));
    CHECK_NOTHROW(chars.add_left('a', 'b'));

    CHECK_THROWS(chars.add_right('f', 'c')); //the tree not contain Node with data 20
    CHECK_THROWS(chars.add_right('f', 'a')); //the tree not contain Node with data 15
    CHECK_THROWS(chars.add_left('g', 'c'));  //the tree not contain Node with data 40
    CHECK_THROWS(chars.add_left('h', 'c'));  //the tree not contain Node with data 30
    CHECK_NOTHROW(cout << chars << endl);

    int pre[] = {'a', 'b', 'd', 'e', 'c'};
    int in[] = {'d', 'b', 'e', 'a', 'c'};
    int post[] = {'d', 'e', 'b', 'c', 'a'};

    int k = 0;
    for (auto it = chars.begin_preorder(); it != chars.end_preorder(); ++it)
    {
        CHECK((*it) == pre[k]);
        k++;
    } 

    k = 0;
    for (auto it = chars.begin_preorder(); it != chars.end_preorder(); ++it)
    {
        CHECK((*it) == in[k]);
        k++;
    } 

    k = 0;
    for (auto it = chars.begin_preorder(); it != chars.end_preorder(); ++it)
    {
        CHECK((*it) == post[k]);
        k++;
    } 
}

TEST_CASE("Custom tree test")
{
    BinaryTree<int> tree;
    CHECK_NOTHROW(tree.add_root(1));
    CHECK_NOTHROW(tree.add_right(1, 2));
    CHECK_NOTHROW(tree.add_left(1, 3));
    CHECK_NOTHROW(tree.add_root(0));
    CHECK_NOTHROW(tree.add_right(2, 4));
    CHECK_NOTHROW(tree.add_right(4, 5));
    CHECK_NOTHROW(tree.add_left(2, 6));
    CHECK_NOTHROW(tree.add_left(6, 7));
    CHECK_NOTHROW(tree.add_left(3, 8));
    CHECK_NOTHROW(tree.add_right(8, 9));
    CHECK_NOTHROW(tree.add_root(-50));
    CHECK_NOTHROW(tree.add_root(1));
}