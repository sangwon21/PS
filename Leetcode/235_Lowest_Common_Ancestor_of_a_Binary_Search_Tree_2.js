/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function (root, p, q) {
    let parentNodesP = [];
    let parentNodesQ = [];
    helper(root, parentNodesP, p, null);
    helper(root, parentNodesQ, q, null);
    for (let i = 0; i < parentNodesP.length; i++) {
        for (let j = 0; j < parentNodesQ.length; j++) {
            if (parentNodesP[i] === parentNodesQ[j]) {
                return parentNodesP[i];
            }
        }
    }
    return null;
};

var helper = function (root, parentNodes, targetNode, parentNode) {
    if (root) {
        if (root === targetNode) {
            parentNodes.push(root);
            return;
        }

        if (targetNode.val < root.val) {
            helper(root.left, parentNodes, targetNode, root);
        }
        else {
            helper(root.right, parentNodes, targetNode, root);
        }

        parentNodes.push(root);
    }
}