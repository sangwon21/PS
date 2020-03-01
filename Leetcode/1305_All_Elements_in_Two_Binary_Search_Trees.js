/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {number[]}
 */
var getAllElements = function(root1, root2) {
  const result = [];
  traverse(root1, result);
  traverse(root2, result);
  result.sort((a, b) => a - b);
  return result;
};

var traverse = function(root, result) {
  if (root) {
    result.push(root.val);
    traverse(root.left, result);
    traverse(root.right, result);
  }
};
