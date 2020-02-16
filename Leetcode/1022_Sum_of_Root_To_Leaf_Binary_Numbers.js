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
var sumRootToLeaf = function (root) {
    const binaryNumbers = [];
    const sum = [];
    traversal(root, binaryNumbers, sum);

    return sum.reduce((acc, cur) => acc + cur, 0);
};

var traversal = function (root, result, sum) {
    if (root) {
        result.push(root.val);
        traversal(root.left, result, sum);
        if (root.left === null && root.right === null) {
            sum.push(convertBinaryIntoDecimal(result));
        }
        traversal(root.right, result, sum);
        result.pop();
        return sum;
    }
}

var convertBinaryIntoDecimal = function (result) {
    return result.reduce((acc, cur) => acc * 2 + cur, 0);
}