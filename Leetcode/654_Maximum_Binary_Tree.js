/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var constructMaximumBinaryTree = function(nums) {
  if (!nums.length) return null;

  const [maxNum, maxIndex] = helper(nums);
  const root = new TreeNode(maxNum);
  root.left = constructMaximumBinaryTree(nums.slice(0, maxIndex));
  root.right = constructMaximumBinaryTree(nums.slice(maxIndex + 1));
  return root;
};

var helper = function(nums) {
  let maxNum = nums[0];
  let maxIndex = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > maxNum) {
      maxNum = nums[i];
      maxIndex = i;
    }
  }
  return [maxNum, maxIndex];
};
