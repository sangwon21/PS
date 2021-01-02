/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} s
 * @param {TreeNode} t
 * @return {boolean}
 */
var isSubtree = function(s, t) {
    if (s) {
        if (isSame(s, t)) {
            return true;
        }
        return isSubtree(s.left, t) || isSubtree(s.right, t);
    }
    return false;
};

var isSame = function(root, newRoot) {
    if (root === null && newRoot === null) {
        return true;
    }
    if (root !== null && newRoot !== null) {
        if (root.val === newRoot.val) {
            return isSame(root.left, newRoot.left) && isSame(root.right, newRoot.right);
        }
        return false;
    }
    
    return false;
}