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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p != nullptr && q == nullptr)
        {
            return false;
        }
        else if(p == nullptr && q != nullptr)
        {
            return false;
        }
        else if(p == nullptr && q == nullptr)
        {
            return true;
        }
        
        if(!isSameTree(p->left, q->left))
        {
            return false;
        }
        if(p->val != q->val)
        {
            return false;
        }
        if(!isSameTree(p->right, q->right))
        {
            return false;
        }
        return true;
    }
};