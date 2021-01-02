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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr && t2 == nullptr)
        {
            return nullptr;
        }
        int val = 0;
        if(t1 == nullptr)
        {
            val = t2->val;
        }
        else if( t2 == nullptr)
        {
            val = t1->val;    
        }
        else
        {
            val = t1->val + t2->val;
        }
        TreeNode* t = new TreeNode(val);
        
        t->left = mergeTrees(t1 == nullptr ? nullptr : t1->left, t2 == nullptr ? nullptr : t2->left);
        t->right = mergeTrees(t1 == nullptr ? nullptr : t1->right, t2 == nullptr ? nullptr : t2->right);
        
        return t;
    }
    
};