/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function (root) {
    if (!root) {
        return [];
    }
    const ans = [];

    const bfs = (root) => {
        const queue = [];
        queue.push({ node: root, level: 0 });

        while (queue.length !== 0) {
            const { node, level } = queue.shift();

            if (!ans[level]) {
                ans[level] = [];
            }

            ans[level].push(node.val);

            node.left && queue.push({ node: node.left, level: level + 1 });
            node.right && queue.push({ node: node.right, level: level + 1 });
        }
    };

    bfs(root);

    return ans;
};
