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
var maxDepth = function (root) {
    if (root === null) {
        return 0;
    }


    return calculateMaxDepth(root, 1);
};

var calculateMaxDepth = function (root, depth) {
    if (root) {
        if (root.left === null && root.right === null) {
            return depth;
        }

        const left = calculateMaxDepth(root.left, depth + 1);
        const right = calculateMaxDepth(root.right, depth + 1);

        return left > right ? left : right;
    }

    return depth
}