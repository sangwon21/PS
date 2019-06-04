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
    TreeNode* xTreeNode;
    int xDepth;
    TreeNode* yTreeNode;
    int yDepth;
    bool isCousins(TreeNode* root, int x, int y) {
        helper(root, x, y, 0, root);
        
        if(xDepth != yDepth)
        {
            return false;
        }
        
        if(xTreeNode == yTreeNode)
        {
            return false;
        }
        
        return true;
    }
    
    void helper(TreeNode* root, int x, int y, int depth, TreeNode* parent)
    {
        if(root == nullptr)
        {
            return;
        }
        if(root->val == x)
        {
            xTreeNode = parent;
            xDepth = depth;
        }
        else if(root->val == y)
        {
            yTreeNode = parent;
            yDepth = depth;
        }
        helper(root->left, x, y, depth + 1, root);
        helper(root->right, x, y, depth + 1, root);
    }
};