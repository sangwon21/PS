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
    TreeNode* head;
    bool findTarget(TreeNode* root, int k) {
        
        if(head == nullptr)
        {
            head = root;
        }
        
        if(root == nullptr)
        {
            return false;
        }
        if(root->val * 2 == k)
        {
            return findTarget(root->left, k) || findTarget(root->right, k);
        }
        
        return findNumber(head, k - root->val) || findTarget(root->left, k) || findTarget(root->right, k);
        
    }
    
    bool findNumber(TreeNode* root, int num)
    {
        if(root == nullptr)
        {
            return false;
        }
        
        if(root->val == num)
        {
            return true;
        }
        else if(root->val < num)
        {
            return findNumber(root->right, num);
        }
        else 
        {
            return findNumber(root->left, num); 
        }
    }
};