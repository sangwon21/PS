/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 */
var FindElements = function(root) {
  helper(root);
  this.root = root;
};

var helper = function(root, val = 0) {
  if (root) {
    root.val = val;
    helper(root.left, val * 2 + 1);
    helper(root.right, val * 2 + 2);
  }
};

/**
 * @param {number} target
 * @return {boolean}
 */
FindElements.prototype.find = function(target, root = this.root) {
  if (root) {
    if (root.val === target) {
      return true;
    }

    return this.find(target, root.right) || this.find(target, root.left);
  }
  return false;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * var obj = new FindElements(root)
 * var param_1 = obj.find(target)
 */
