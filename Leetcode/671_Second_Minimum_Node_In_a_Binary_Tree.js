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
var findSecondMinimumValue = function(root) {
    if (root === null) {
        return -1;
    }
    const secondMin = helper(root, root.val);
    
    return secondMin === root.val ? -1 : secondMin;
};

var helper = function(root, originalValue) {
    if(root) {
        if (root.val !== originalValue) {
            return root.val;
        }
        
        const left = helper(root.left, originalValue);
        const right = helper(root.right, originalValue);
        
        if (left === originalValue) {
            return right;
        }
        if (right === originalValue) {
            return left;
        }
        
        return left > right ? right : left;
    }
    return originalValue;
}