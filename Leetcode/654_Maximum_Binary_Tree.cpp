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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return nullptr;
        }
        
        TreeNode* root = construct(0, nums.size() -1, nums);
        
        return root;
    }
    
    TreeNode* construct(int start, int end, vector<int>& nums)
    {
        if(start > end)
        {
            return nullptr;
        }
        
        int ptr = start;
        int maxNum = nums[start];
        for(unsigned int i = start + 1; i <= end; i++)
        {
            if(maxNum < nums[i])
            {
                maxNum = nums[i];
                ptr = i;
            }
        }
        
        TreeNode * node = new TreeNode(maxNum);
        
        node->left = construct(start, ptr -1, nums);
        node->right = construct(ptr + 1, end, nums);
            
        return node;
    }
};