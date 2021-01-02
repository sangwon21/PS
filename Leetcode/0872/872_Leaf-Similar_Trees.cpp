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
    vector<int> leaf1;
    vector<int> leaf2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    
        addLeaves(leaf1, root1);
        addLeaves(leaf2, root2);
        
        if(leaf1.size() != leaf2.size())
        {
            return false;
        }
        
        for(unsigned int i = 0; i < leaf1.size(); i++)
        {
            if(leaf1[i] != leaf2[i])
            {
                return false;
            }
        }
        return true;
    }
    
    void addLeaves(vector<int>& leaf, TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        addLeaves(leaf, root->left);
        if(root->left == nullptr && root->right == nullptr)
        {
            leaf.push_back(root->val);
        }
        addLeaves(leaf, root->right);
    }
};