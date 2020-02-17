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
var sumOfLeftLeaves = function(root) {
    return helper(root, 0);
};

var helper = function (root, sum) {
    if(root) {
        if (root.left && root.left.left === null && root.left.right === null) {
            return helper(root.left, sum) + helper(root.right, sum) + sum + root.left.val;
        }
        return helper(root.left, sum) + helper(root.right, sum) + sum;
    }
    return sum;
}