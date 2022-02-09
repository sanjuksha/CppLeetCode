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
///\brief:Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure
/// and node values of subRoot and false otherwise.A subtree of a binary tree tree is a tree that consists of a node in tree
/// and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if(!subRoot)
            return true;
        if(!root)
            return false;

        if(isSameTree(root,subRoot))
            return true;

        return (isSubtree(root->left, subRoot) ||
                isSubtree(root->right, subRoot));
    }

    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
            return true;
        if(p and q and p->val == q->val)
            return (isSameTree(p->left,q->left) &&
                isSameTree(p->right,q->right));
        return false;
    }
};

int main()
{
    std::cout<<"LeetCode Problem 572: Sub tree of another tree"<<std::endl;
    TreeNode* left, *right, *root, *subRoot, *left1,*left2;
    left1 = new TreeNode(1);
    left2 = new TreeNode(2);
    subRoot = new TreeNode(4, left1, left2);
    left = new TreeNode(4,left1,left2);
    right = new TreeNode(5);
    root = new TreeNode(3, left, right) ;


    Solution solution;

    bool result;
    result = solution.isSubtree(root,subRoot);
    std::stringstream ss;
    ss << std::boolalpha << result;
    std::cout<<ss.str()<<std::endl;

    delete root,subRoot,left2,left1,left,right;

}