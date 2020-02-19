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
var findTilt = function (root) {
    tilt(root, 0);
    return traverseAndGetSum(root, 0);
};

var tilt = function (root, sum) {
    if (root) {
        const leftSum = tilt(root.left, sum);
        const rightSum = tilt(root.right, sum);


        const originalRootVal = root.val;
        root.val = Math.abs(leftSum - rightSum);

        return originalRootVal + leftSum + rightSum;
    }
    return 0;
}

var traverseAndGetSum = function (root, sum) {
    if (root) {
        const leftSum = traverseAndGetSum(root.left, sum);
        const rightSum = traverseAndGetSum(root.right, sum);

        return root.val + leftSum + rightSum;
    }
    return 0;
}