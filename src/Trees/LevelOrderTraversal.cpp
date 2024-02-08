/**
 * @file LevelOrderTraversal.cpp
 * @author Sanjuksha Nirgude
 * @brief Given the root of a binary tree, return the level order traversal
 *  of its nodes' values. (i.e., from left to right, level by level).
 * 
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 * 
 * @date 2024-01-23
 */

#include <iostream>
#include <queue>
#include <vector>
#include "../Print/MatrixPrinter.cpp"


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
     * @name level order traversal for a vector
     * @brief 
     * Check the base case of root being null - return empty result
     * Initiate the q with root
     * while queue is not empty
     *  store the length of queue as it might change later
     *  iterate through the current length of the queue
     *  pop out the front of the queue
     *  add it's children to the back of the queue
     *  save the values of the node in a level vector
     * concatenate all level vectors to result
     * 
     * @param root 
     * @return std::vector<std::vector<int>> 
     */
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> result;
        if(!root)
            return result;

        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int qLen = q.size();
            std::vector<int> level;
            for(int i = 0; i < qLen; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left != nullptr)
                {
                    q.push(node->left);
                }
                if(node->right != nullptr)
                {
                    q.push(node->right);
                }

            }
            result.push_back(level);

        }
        return result;

    }


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

    // Level order traversal
    std::cout<<"LeetCode 102: Binary Tree Level Order Traversal \n";

    Solution solution;
    std::vector<std::vector<int>> result;
    result = solution.levelOrder(root);


    //Print Result
    std::cout<<"{ ";
    for(int i = 0; i<result.size(); i++)
    {
        std::cout<<"[ ";
        for(int j = 0; j<result[i].size(); j++)
        {
            std::cout<<result[i][j]<<" , ";
        }
        std::cout<<"] ";
    }
    std::cout<<" } ";

}