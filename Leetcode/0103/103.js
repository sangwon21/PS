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
var zigzagLevelOrder = function (root) {
	if (!root) {
		return [];
	}

	const answer = [];

	const q = [];
	q.push({ node: root, depth: 1 });

	while (q.length !== 0) {
		const { node, depth } = q.shift();

		if (!answer[depth - 1]) {
			answer[depth - 1] = [node.val];
		} else {
			answer[depth - 1].push(node.val);
		}

		node.left && q.push({ node: node.left, depth: depth + 1 });
		node.right && q.push({ node: node.right, depth: depth + 1 });
	}

	for (let i = 1; i < answer.length; i += 2) {
		answer[i].reverse();
	}

	return answer;
};
