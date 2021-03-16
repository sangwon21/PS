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
 * @return {boolean}
 */
var isValidBST = function (root) {
	const isValid = (root, minVal, maxVal) => {
		if (!root) {
			return true;
		}

		if ((maxVal !== null && root.val >= maxVal) || (minVal !== null && root.val <= minVal)) {
			return false;
		}

		return isValid(root.left, minVal, root.val) && isValid(root.right, root.val, maxVal);
	};

	return isValid(root, null, null);
};
