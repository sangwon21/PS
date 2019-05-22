/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <math.h>
class Solution {
  public:
       int res = INT_MAX, pre = -1;
        int minDiffInBST(TreeNode* root) {
            if(root == nullptr)
            {
                return INT_MAX;
            }
            minDiffInBST(root->left);
            if(pre >= 0)
            {
                res = min(res, root->val - pre);
            }
            pre = root->val;
            minDiffInBST(root->right); 
                        
            return res;
        }
};