/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} target
 * @return {TreeNode}
 */
var removeLeafNodes = function(root, target) {
  return helper(root, target, null);
};

var helper = function(root, target, parentNode) {
  if (root) {
    helper(root.left, target, root);
    helper(root.right, target, root);

    if (root.left === null && root.right === null && root.val === target) {
      if (parentNode === null) {
        return null;
      }

      if (parentNode.left === root) {
        parentNode.left = null;
        return root;
      }
      parentNode.right = null;
      return root;
    }
    return root;
  }
  return null;
};
