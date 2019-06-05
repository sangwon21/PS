/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cmath>
class Solution {
public:
    int res = INT_MAX;
    int pre = INT_MIN;
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }
        
        getMinimumDifference(root->left);
        if(pre != INT_MIN)
        {
            int n1 = root->val < 0 ? -root->val : root->val;
            int n2 = pre < 0 ? -pre : pre;
            res = res > abs(n1 - n2) ? abs(n1 - n2) : res;
        }
        pre = root->val;
        getMinimumDifference(root->right);
        
        return res;
    }
};