#define BOOST_TEST_MODULE bst
#include "../BST.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(case0)
{
    BST bst;
    bst.root = bst.insertIntoBST(bst.root, 1);
    bst.insertIntoBST(bst.root, 2);
    bst.insertIntoBST(bst.root, 3);
    BOOST_CHECK_EQUAL(bst.isValidBST(bst.root), true);
}

BOOST_AUTO_TEST_CASE(case1)
{
    BST bst;
    bst.root = bst.insertIntoBST(bst.root, 1);
    bst.insertIntoBST(bst.root, 2);
    bst.insertIntoBST(bst.root, 3);
    TreeNode *node = bst.searchBST(bst.root, 3);
    BOOST_CHECK_EQUAL(node->val, 3);
    node = bst.searchBST(bst.root, 4);
    BOOST_CHECK_EQUAL(node, nullptr);
}

BOOST_AUTO_TEST_CASE(case2)
{
    BST bst;
    bst.root = bst.insertIntoBST(bst.root, 1);
    bst.insertIntoBST(bst.root, 2);
    bst.insertIntoBST(bst.root, 3);
    TreeNode *node = bst.searchBST(bst.root, 3);
    BOOST_CHECK_EQUAL(node->val, 3);
    bst.deleteNode(bst.root,3);
    node = bst.searchBST(bst.root, 3);
    BOOST_CHECK_EQUAL(node, nullptr);
}