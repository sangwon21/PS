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
    bool isSymmetric(TreeNode* root) {
        TreeNode* other;
        other = makeSymmetric(other, root);
        
        return isSame(root, other);
    }
    
    bool isSame(TreeNode* original, TreeNode* other)
    {
        if(original == nullptr && other == nullptr)
        {
            return true;
        }
        
        if(original == nullptr || other == nullptr)
        {
            return false;
        }
        
        if(original->val == other->val)
        {
            return isSame(original->left, other->left) && isSame(original->right, other->right);
        }
        
        else
        {
            return false;
        }
    }
    
    TreeNode* makeSymmetric(TreeNode* root, TreeNode* original)
    {
        if(original == nullptr)
        {
            return nullptr;
        }
        
        root = new TreeNode(original->val);
        
        root->left = makeSymmetric(root->left, original->right);
        root->right = makeSymmetric(root->right, original->left);
        
        return root;
    }
};