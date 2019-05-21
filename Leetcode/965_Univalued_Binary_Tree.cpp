/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* prev;
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr)
        {
            return true;
        }
        
        if(root->left != nullptr)
        {
            if(!isUnivalTree(root->left))
            {
                return false;
            }
            if(root->val != root->left->val)
            {
                return false;
            }
        }
        
        if(root->right != nullptr)
        {
            if(!isUnivalTree(root->right))
            {
                return false;
            }
            if(root->val != root->right->val)
            {
                return false;
            }
        }
        
        return true;
    }
};