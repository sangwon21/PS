/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} x
 * @param {number} y
 * @return {boolean}
 */
let leftDepth = 0;

var isCousins = function (root, x, y) {
    helper(root, x, 0);
    return traversal(root, y, 0, root, x);
};

var helper = function (root, target, depth) {
    if (root) {
        helper(root.left, target, depth + 1);
        if (root.val === target) {
            leftDepth = depth;
            return;
        }
        helper(root.right, target, depth + 1);
    }
}

var traversal = function (root, target, depth, parentNode, compareValue) {
    if (root && depth <= leftDepth) {
        if (root.val === target && depth === leftDepth) {
            if ((parentNode.left && parentNode.left.val === compareValue) || (parentNode.right && parentNode.right.val === compareValue)) {
                return false;
            }
            return true;
        }
        return traversal(root.right, target, depth + 1, root, compareValue) || traversal(root.left, target, depth + 1, root, compareValue);
    }
    return false;
}