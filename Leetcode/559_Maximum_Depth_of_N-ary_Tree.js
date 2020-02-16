/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */
/**
 * @param {Node} root
 * @return {number}
 */


var maxDepth = function (root, length = 1) {
    if (root) {
        let maxDep = length;

        root.children.forEach(child => {
            const childMaxDep = maxDepth(child, length + 1);
            maxDep = maxDep > childMaxDep ? maxDep : childMaxDep;
        })

        return maxDep;
    }
    return 0;
};