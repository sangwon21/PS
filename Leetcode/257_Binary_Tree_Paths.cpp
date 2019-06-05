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
    vector<string> ans;
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr)
        {
            return ans;
        }   
        if(root->left == nullptr && root->right == nullptr)
        {
            string s = to_string(root->val);
            ans.push_back(s);
        }
        else
        {
            helper(root, to_string(root->val));   
        }
        
        return ans;
    }
    
    void helper(TreeNode* root, string s)
    {
        if(root != nullptr)
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                ans.push_back(s);
            }
            
            if(root->left != nullptr)
            {
                helper(root->left, s + "->" + to_string(root->left->val));
            }
            
            if(root->right != nullptr)
            {
                helper(root->right, s + "->" + to_string(root->right->val));
            }
        }
    }
};