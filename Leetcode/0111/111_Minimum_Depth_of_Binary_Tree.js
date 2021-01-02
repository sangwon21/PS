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
var minDepth = function(root) {
    if (root === null) {
        return 0;
    }
    return helper(root, 1);
};

var helper = function(root, depth) {
    if (root) {
        if (root.left === null && root.right === null) {
            return depth;
        }
        
        if (root.right === null) {
            return helper(root.left, depth + 1);
        }
        
        if (root.left === null) {
            return helper(root.right, depth + 1);
        }
        
        const leftDepth = helper(root.left, depth + 1);
        const rightDepth = helper(root.right, depth + 1);
        
        return leftDepth > rightDepth ? rightDepth : leftDepth;
    }
    return depth;
}