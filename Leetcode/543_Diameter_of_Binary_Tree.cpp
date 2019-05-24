/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <math.h>

class Solution {
public:
    int res = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }
        
        int left = findMaxDiameter(root->left);
        int right = findMaxDiameter(root->right);
        
        if(res < left + right)
        {
            res = left + right;
        }
        
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        
        return res;
    }
    
    int findMaxDiameter(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int left = findMaxDiameter(root->left);
        int right = findMaxDiameter(root->right);
        
        if(left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
    }
};