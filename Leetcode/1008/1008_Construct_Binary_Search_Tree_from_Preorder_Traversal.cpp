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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode* root = nullptr;
        
        for(unsigned int i = 0; i < preorder.size(); i++)
        {
            root = construct(root, preorder[i]);
        }
        
        return root;
    }
    
    TreeNode* construct(TreeNode* root, int val)
    {
        if(root == nullptr)
        {
            return new TreeNode(val);
        }
        
        if(val > root->val)
        {
            root->right = construct(root->right, val);
        }
        else
        {
            root->left = construct(root->left, val);
        }
        
        return root;
    }