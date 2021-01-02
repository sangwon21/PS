/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} t1
 * @param {TreeNode} t2
 * @return {TreeNode}
 */
var mergeTrees = function (t1, t2) {
    if (t1 || t2) {
        const t1Val = t1 ? t1.val : 0;
        const t2Val = t2 ? t2.val : 0;

        const root = new TreeNode(t1Val + t2Val);

        root.left = mergeTrees(t1 ? t1.left : null, t2 ? t2.left : null);
        root.right = mergeTrees(t1 ? t1.right : null, t2 ? t2.right : null);

        return root;
    }
    return null;
};