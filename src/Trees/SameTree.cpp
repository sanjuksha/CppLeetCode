/**
 * @file SameTree.cpp
 * @author Sanjuksha Nirgude
 * @brief Given the roots of two binary trees p and q,
 * write a function to check if they are the same or not.
 * Two binary trees are considered the same if they are structurally identical,
 * and the nodes have the same value.
 * 
 * Example 1:
 * Input: p = [1,2,3], q = [1,2,3]
 * Output: true
 * @date 2024-02-07
 */

#include <iostream>
#include <vector>
#include <sstream>


/**
 * Definition for a binary tree node.
 **/

struct TreeNode {
  int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

///\class : Solution to Same Tree
///\brief: Given the roots of two binary trees p and q, this function checks if they are the same or not.
/// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(!p && !q) // both sides of tree are empty
            return true;
        if(!p || !q || p->val != q->val) // only one tree exists or if the values differ
            return false;

        return (isSameTree(p->left,q->left) &&
                isSameTree(p->right,q->right)); // recursively scan he entire tree
    }
};

int main()
{
    std::cout<<"LeetCode Problem 100: Same Tree"<<std::endl;
    TreeNode* left, *right, *p, *q;
    left = new TreeNode(2);
    right = new TreeNode(3);
    p = new TreeNode(1, left, right) ;
    q = new TreeNode(1, left, right);

    Solution solution;

    bool result;
    result = solution.isSameTree(p,q);
    std::stringstream ss;
    ss << std::boolalpha << result;
    std::cout<<ss.str()<<std::endl;

    delete p,q,left,right;

}
