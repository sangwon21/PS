/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {string[]}
 */
var binaryTreePaths = function(root) {
    let result = [];
    let path = "";
    
    helper(root, result, path);
    return result;
};

const helper = function(root, result, path) {
    if (root) {
        path = path === "" ? `${root.val}` : `${path}->${root.val}`;
        if (root.left === null && root.right === null) {
            result.push(path);
            return;
        }
        
        root.left ? helper(root.left, result, path) : null;
        root.right ? helper(root.right, result, path) : null;
    }
}