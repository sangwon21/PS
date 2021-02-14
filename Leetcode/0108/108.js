/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function (nums) {
    if (nums.length <= 0) {
        return null;
    }

    const pivot = parseInt(nums.length / 2);
    const target = nums[pivot];

    const node = new TreeNode(target, null, null);

    node.left = sortedArrayToBST(nums.slice(0, pivot));
    node.right = sortedArrayToBST(nums.slice(pivot + 1));

    return node;
};
