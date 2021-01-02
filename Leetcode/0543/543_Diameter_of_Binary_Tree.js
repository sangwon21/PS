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
var diameterOfBinaryTree = function(root) {
    return traversal(root, 0);
};

var traversal = function(root, diameter) {
    if (root) {
        let rootDiameter = (root.left ? calculateMaxDepth(root.left, 1) : 0) + (root.right ? calculateMaxDepth(root.right, 1) : 0);
        
        diameter = rootDiameter > diameter ? rootDiameter : diameter; 
        const leftDiameter = traversal(root.left, diameter);
        const rightDiameter = traversal(root.right, diameter);
        
        const compare = leftDiameter > rightDiameter ? leftDiameter : rightDiameter;
        
        return compare > diameter ? compare : diameter;
    }
    return diameter;
}

var calculateMaxDepth = function(root, depth) {
    if (root) {
        const right = root.right ? calculateMaxDepth(root.right, depth + 1) : depth;
        const left = root.left ? calculateMaxDepth(root.left, depth + 1) : depth;
        
        return right > left ? right : left;
    }
    return depth;
}