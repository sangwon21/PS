/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */
/**
 * @param {Node} root
 * @return {number[]}
 */
var postorder = function (root, result = []) {
    if (root) {
        root.children.forEach(child => postorder(child, result));

        result.push(root.val);

        return result;
    }

    return [];
};