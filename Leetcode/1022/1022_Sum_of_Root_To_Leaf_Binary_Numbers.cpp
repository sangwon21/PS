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
    vector<int> v;
    int sumRootToLeaf(TreeNode* root) {
        rootToLeaf(root, "");
        int sum = 0;
        for(unsigned int i = 0; i < v.size(); i++)
        {
            sum += v[i];
        }
        
        return sum;
    }
    
    void rootToLeaf(TreeNode* root, string s)
    {
        if(root == nullptr)
        {
            return;
        }
        if(root->left == nullptr && root->right == nullptr)
        {
            v.push_back(convertIntoDecimal(s + to_string(root->val)));
            return;
        }
        
        rootToLeaf(root->left, s + to_string(root->val));
        rootToLeaf(root->right, s + to_string(root->val));
    }
    
    int convertIntoDecimal(string s)
    {
        int decimal = 0;
        for(int i = 0; i < s.size(); i++)
        {
            decimal = decimal * 2 + s[i] - '0';
        }
        
        return decimal;
    }
};