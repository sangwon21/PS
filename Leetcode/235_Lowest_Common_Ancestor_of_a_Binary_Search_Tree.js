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
var lowestCommonAncestor = function(root, p, q) {
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

var helper = function(root, parentNodes, targetNode, parentNode) {
    if (root) {
        if (root === targetNode) {
            parentNodes.push(root);    
            return true;
        }
        const left = helper(root.left, parentNodes, targetNode, root);
        const right = helper(root.right, parentNodes, targetNode, root);
        
        if (left === true || right === true) {
            parentNodes.push(root);
        }
        
        return left || right;
    }
    return false;
}