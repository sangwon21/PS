/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isUnivalTree = function (root) {
    return traversal(root, root.val);
};

const traversal = (node, val) => {
    if (node) {
        const nodeVal = node.val;
        if (val !== nodeVal) {
            return false;
        }

        return traversal(node.left, val) && traversal(node.right, val);
    }
    return true;
}