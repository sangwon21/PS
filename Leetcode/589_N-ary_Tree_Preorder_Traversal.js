/**
 * // Definition for a Node.
 * function Node(val, children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */
/**
 * @param {Node} root
 * @return {number[]}
 */
var preorder = function (root, result = []) {
    if (root) {
        result.push(root.val);

        root.children.forEach(node => {
            preorder(node, result);
        })

        return result;
    }
    return [];
};