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
    TreeNode* pre;
    TreeNode* start;
    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr)
        {
            return nullptr;
        }
       
        increasingBST(root->left);
        if(start == nullptr)
        {
            TreeNode* t = new TreeNode(root->val);
            start = t;
            pre = start;
        }
        else
        {
            TreeNode* t = new TreeNode(root->val);
            pre->right = t;
            pre = t;
        }
        increasingBST(root->right);
        
        return start;
    }
};