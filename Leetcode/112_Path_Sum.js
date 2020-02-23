/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {boolean}
 */
var hasPathSum = function(root, sum) {
    return helper(root, 0, sum);
};

var helper = function (root, sum, target) {
    if (root) {
        if (root.val + sum === target && (root.left === null && root.right === null)) {
            return true;
        }
        return helper(root.left, sum + root.val, target) || helper(root.right, sum + root.val, target);
    }
    return false;
}