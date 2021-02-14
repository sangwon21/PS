/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function (preorder, inorder) {
    if (!inorder || inorder.length === 0) {
        return null;
    }

    const rootVal = preorder.shift();
    const rootNode = new TreeNode(rootVal, null, null);
    const rootValIndex = inorder.indexOf(rootVal);
    const leftTreeInorder = inorder.slice(0, rootValIndex);
    const rightTreeInorder = inorder.slice(rootValIndex + 1);

    if (rootValIndex === -1) {
        return null;
    }

    rootNode.left = buildTree(preorder, leftTreeInorder);
    rootNode.right = buildTree(preorder, rightTreeInorder);

    return rootNode;
};
