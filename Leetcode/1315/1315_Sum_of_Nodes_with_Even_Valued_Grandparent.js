/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumEvenGrandparent = function(root) {
  const result = [];
  helper(root, result);
  return result.reduce((acc, cur) => (acc += cur), 0);
};

var helper = function(root, result) {
  if (root) {
    if (root.val % 2 === 0) {
      if (root.left) {
        root.left.left && result.push(root.left.left.val);
        root.left.right && result.push(root.left.right.val);
      }
      if (root.right) {
        root.right.left && result.push(root.right.left.val);
        root.right.right && result.push(root.right.right.val);
      }
    }

    helper(root.left, result);
    helper(root.right, result);
  }
};
