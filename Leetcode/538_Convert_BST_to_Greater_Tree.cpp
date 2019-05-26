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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        
        traversal(root);
        return root;
    }
    
    void traversal(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
       
        if(root->right != nullptr) traversal(root->right);
        root->val = root->val + sum;
        sum = root->val;
        if(root->left != nullptr) traversal(root->left); 
        
    }

};