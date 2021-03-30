/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} target
 * @param {number} K
 * @return {number[]}
 */
var distanceK = function (root, target, K) {
	const ans = [];
	const dfs = (root, target, k, depth) => {
		if (!root) {
			return 0;
		}

		if (k === depth) {
			ans.push(root.val);
			return 0;
		}

		let left, right;
		if (root === target || depth > 0) {
			left = dfs(root.left, target, k, depth + 1);
			right = dfs(root.right, target, k, depth + 1);
		} else {
			left = dfs(root.left, target, k, depth);
			right = dfs(root.right, target, k, depth);
		}

		if (root === target) {
			return 1;
		}

		if (k === left || k === right) {
			ans.push(root.val);
			return 0;
		}

		if (left > 0) {
			dfs(root.right, target, K, left + 1);
			return left + 1;
		}

		if (right > 0) {
			dfs(root.left, target, K, right + 1);
			return right + 1;
		}

		return 0;
	};

	if (K === 0) {
		return [target.val];
	}

	dfs(root, target, K, 0);
	return ans;
};
