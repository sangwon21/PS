/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cmath>

class Solution {
public:
    int findTilt(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }
        
        if(root->left == nullptr && root->right == nullptr)
        {
            return 0;
        }
        
        if(root->left == nullptr)
        {
            return findTilt(root->right) + abs(findSum(root->right));
        }
        
        if(root->right == nullptr)
        {
            return findTilt(root->left) + abs(findSum(root->left));
        }
        
        int left = findSum(root->left);
        int right = findSum(root->right);
        
        return abs(left - right) + findTilt(root->right) + findTilt(root->left);
    }
    
    int findSum(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        
        return root->val + findSum(root->left) + findSum(root->right);
    }
};