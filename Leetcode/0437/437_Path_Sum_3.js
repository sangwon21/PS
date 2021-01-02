/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number}
 */
var pathSum = function(root, sum) {
    let result = [];
    go(root, sum, result);
    return result.length;
};

var go = function(root, target, result) {
    if (root) {
        traverse(root, 0, target, result);
        go(root.left, target, result);
        go(root.right, target, result);
    }
}

var traverse = function(root, sum, target, result) {
    if (root) {
        
        sum += root.val;
        
        if (sum === target) {
            result.push(true);
        }
        
        traverse(root.left, sum, target, result)
        traverse(root.right, sum,  target, result);
    }
}