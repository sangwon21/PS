/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrderBottom = function(root) {
    let result = [];
    helper(root, 0, result);
    return result.reverse();
};

var helper = function(root, depth, result) {
    if (root) {
        helper(root.left, depth + 1, result);
        if (result[depth] === undefined) {
            result[depth] = [];
        }
        result[depth].push(root.val);
        helper(root.right, depth + 1, result);
    }
}