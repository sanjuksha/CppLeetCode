/**
 * @file MaximumDepthOfTree.cpp
 * @author Sanjuksha Nirgude
 * @date 2024-01-23
 *
 * @brief 
 *  Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along 
 * the longest path from the root node down to the farthest leaf node.
 * 
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output = 3
 */

// There are three ways to solve this problem 

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r){}
};


class Solution
{
public:
    /**
     * @name Max Depth using Recursion & DFS
     * @brief
     * Base case of recursion - check if root is null
     * initialize depth = 0 to start with
     * Invoke recursion -
     * if root is not null the recusively find depth of left and right nodes of root
     * return whichever is max and add 1 to it since we started depth at 0
     * 
     * @param root 
     * @return max depth of the tree
     */
    int maxDepthRecursionDFS(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int depth = 0;

        return(1 + std::max(maxDepthRecursionDFS(root->left),
        maxDepthRecursionDFS(root->right)));
    }
    /**
     * @name Max Depth using recursion and BFS
     * @brief Here we check how many levels the tree has
     * Base Case of recursion - Start with checking if root is null then return 0
     * Start with level being 0
     * Invoke Recursion - If root not null make a queue with root node in it
     * while queue is not empty
     * for the length of the queue's current level
     * save the first node in a temp variable
     * then pop the first inserted node in queue
     * then add it's children into it if they are not null
     * and increment the level
     * After all iterations queue would be empty and we can return the level
     * @param root 
     * @return level - max depth of the tree
     */

    int maxDepthRecursionBFS(TreeNode* root)
    {
        if(!root)
            return 0;

        int level = 0;
        std::queue< TreeNode*> depthQ;
        depthQ.push(root);
        while(!depthQ.empty())
        {
            int count = depthQ.size();
            for(int i = 0; i < count; i++)
            {
                TreeNode* node = depthQ.front();
                depthQ.pop();
                if(node->left != nullptr)
                {
                    depthQ.push(node->left);
                }
                if(node->right != nullptr)
                {
                    depthQ.push(node->right);
                }
                
            }
            level++;
        }
        return level;
    }

    // /**
    //  * @name Max Depth using a iterative DFS
    //  * @brief Here we don't use recursion, instead use a stack
    //  * 
    //  * 
    //  * @param root 
    //  * @return int 
    //  */
    // int maxDepthIterativeDFS(TreeNode* root)
    // {

    // }
};

int main()
{
    //Define a tree
    TreeNode* root = new TreeNode(3);
    TreeNode* left1 = new TreeNode(9);
    TreeNode* right1 = new TreeNode(20);
    TreeNode* left2 = new TreeNode(15);
    TreeNode* right2 = new TreeNode(7);
    
    root->left = left1;
    root->right = right1;

    root->right->left = left2;
    root->right->right = right2;

    std::cout<<"root: "<<"["<<root->val<<","<<root->left->val<<","
        <<root->right->val<<","<<root->right->left->val<<","<<
        root->right->right->val<<"]"<<std::endl;

    // Find Max Depth
    std::cout<<"LeetCode 104: Maximum Depth of Binary Tree \n";

    Solution solution;
    int recursiveDFS = solution.maxDepthRecursionDFS(root);
    int recursiveBFS = solution.maxDepthRecursionBFS(root);
    // int iterativeDFS = solution.maxDepthIterativeDFS(root);

    if(recursiveBFS == recursiveDFS)
    // && recursiveBFS == iterativeDFS)
    {
        std::cout<<"Maximum Depth : "<<recursiveBFS<<"\n";
    }
    else
    {
        std::cout<<"Error: Algorithm mismatch!! \n";
    }
}