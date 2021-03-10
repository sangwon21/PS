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
 * @return {number[]}
 */
var rightSideView = function (root) {
	if (!root) {
		return [];
	}

	const ans = [];

	const q = [];
	q.push({ root, depth: 0 });
	while (q.length !== 0) {
		const { root, depth } = q.shift();

		ans[depth] = root.val;

		root.left && q.push({ root: root.left, depth: depth + 1 });
		root.right && q.push({ root: root.right, depth: depth + 1 });
	}

	return ans;
};
