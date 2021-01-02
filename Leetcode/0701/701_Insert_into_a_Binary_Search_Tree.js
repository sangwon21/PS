/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} val
 * @return {TreeNode}
 */
var insertIntoBST = function(root, val) {
  helper(root, val);
  return root;
};

var helper = function(root, val) {
  console.log("root is ", root);
  if (root === null) {
    return new TreeNode(val);
  }
  if (root.val > val) {
    root.left = helper(root.left, val);
    return root;
  }
  root.right = helper(root.right, val);
  return root;
};
