#include <iostream>
#include <vector>

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
///\class Solution InvertTree
///\brief Given the root of a binary tree, invert the tree, and return its root.
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if(!root)
            return nullptr;
        auto temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};



int main()
{
    std::cout<<"LeetCode Problem 226: Invert Binary Tree"<<std::endl;
    TreeNode* left, *right, *root, *left1,*left2, *right1,*right2;
    left1 = new TreeNode(1);
    left2 = new TreeNode(3);
    right1 = new TreeNode(6);
    right2 = new TreeNode(9);
    left = new TreeNode(2,left1,left2);
    right = new TreeNode(7,right1,right2);
    root = new TreeNode(4, left, right) ;
    std::cout<<"root: "<<"["<<root->val<<","<<root->left->val<<","<<root->right->val<<","<<root->left->left->val<<","<<root->left->right->val<<","<<root->right->left->val<<","<<root->right->right->val<<"]"<<std::endl;


    Solution solution;

    root = solution.invertTree(root);
    std::cout<<"root result: "<<"["<<root->val<<","<<root->left->val<<","<<root->right->val<<","<<root->left->left->val<<","<<root->left->right->val<<","<<root->right->left->val<<","<<root->right->right->val<<"]"<<std::endl;

    delete root,right1,right2,left2,left1,left,right;

}