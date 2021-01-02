/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var increasingBST = function (root) {
    const result = [];
    traversal(root, result);
    let newRoot = null;
    let beforeNode = null;
    result.forEach(val => {
        if (newRoot === null) {
            newRoot = new TreeNode(val);
            newRoot.right = null;
            newRoot.left = null;
            beforeNode = newRoot;
        } else {
            beforeNode.right = new TreeNode(val);
            beforeNode.left = null;
            beforeNode = beforeNode.right;
        }
    })

    return newRoot;
};

const traversal = (root, result) => {
    if (root) {
        traversal(root.left, result);
        result.push(root.val);
        traversal(root.right, result);
    }
}