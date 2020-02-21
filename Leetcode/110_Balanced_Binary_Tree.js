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
var isBalanced = function(root) {
    return helper(root);  
  };
  
  var helper = function(root) {
      if(root){
          if (root.left === null && root.right === null) {
              return true;
          }
          
          const leftMaxDepth = calculateMaxDepth(root.left, 0);
          const rightMaxDepth = calculateMaxDepth(root.right, 0);
          
          if (Math.abs(leftMaxDepth - rightMaxDepth) > 1) {
              return false;
          }
          
          return helper(root.left) && helper(root.right);
      }
      return true;
  }
  
  var calculateMaxDepth = function(root, depth) {
      if (root) {
          const left = calculateMaxDepth(root.left, depth + 1);
          const right = calculateMaxDepth(root.right, depth + 1);
          
          return left > right ? left : right;
      }
      return depth;
  }