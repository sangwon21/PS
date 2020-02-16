/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */
var leafSimilar = function (root1, root2) {
    let result1 = [];
    let result2 = [];

    traversal(root1, result1);
    traversal(root2, result2);

    if (result1.length !== result2.length) {
        return false;
    }

    for (let i = 0; i < result1.length; i++) {
        if (result1[i] !== result2[i]) {
            return false;
        }
    }

    return true;
};

const traversal = (root, result) => {
    if (root) {
        traversal(root.left, result);
        if (root.left === null && root.right === null) {
            result.push(root.val);
        }
        traversal(root.right, result);
    }
}