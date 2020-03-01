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
var deepestLeavesSum = function(root) {
  const result = [];
  helper(root, result, 0);
  result.sort((a, b) => b.depth - a.depth);
  const max = result[0].depth;
  let ans = 0;

  for (let i = 0; i < result.length; i++) {
    if (result[i].depth !== max) {
      break;
    }
    ans += result[i].val;
  }

  return ans;
};

var helper = function(root, result, depth) {
  if (root) {
    if (root.left === null && root.right === null) {
      result.push({ val: root.val, depth });
      return;
    }
    helper(root.left, result, depth + 1);
    helper(root.right, result, depth + 1);
  }
};
