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
var isSymmetric = function (root) {
    const newRoot = reverse(root, null);

    return testSymmetric(root, newRoot);
};

var reverse = function (root, newRoot) {
    if (root) {

        if (newRoot === null) {
            newRoot = new TreeNode(root.val);
        }

        newRoot.right = root.left ? new TreeNode(root.left.val) : null;
        newRoot.left = root.right ? new TreeNode(root.right.val) : null;

        reverse(root.left, newRoot.right);
        reverse(root.right, newRoot.left);

        return newRoot;
    }
    return null;
}

var traverse = function (root) {
    if (root) {
        traverse(root.left);
        console.log(root.val)
        traverse(root.right);
    }
}

var testSymmetric = function (root, newRoot) {
    if (root && newRoot) {
        if (root.val === newRoot.val) {
            return testSymmetric(root.left, newRoot.left) && testSymmetric(root.right, newRoot.right);
        }
        return false;
    }
    if (!root && !newRoot) {
        return true;
    }
    if (root || newRoot) {
        return false;
    }
}