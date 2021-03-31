/**
 * @param {number} n
 * @return {string[][]}
 */
var solveNQueens = function (n) {
	const board = [];

	for (let i = 0; i < n; i++) {
		const arr = [];
		for (let j = 0; j < n; j++) {
			arr.push(".");
		}
		board.push(arr);
	}

	const ans = [];

	const isValid = (row, col) => {
		for (let i = 0; i != row; ++i) {
			if (board[i][col] == "Q") {
				return false;
			}
		}

		for (let i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
			if (board[i][j] == "Q") {
				return false;
			}
		}

		for (let i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
			if (board[i][j] == "Q") {
				return false;
			}
		}
		return true;
	};

	const traverse = (row) => {
		if (row === n) {
			const copy = [];
			for (let i = 0; i < board.length; i++) {
				copy.push(board[i].join(""));
			}
			ans.push(copy);
			return;
		}

		for (let col = 0; col < n; col++) {
			board[row][col] = "Q";
			if (isValid(row, col)) {
				traverse(row + 1);
			}
			board[row][col] = ".";
		}
	};

	traverse(0, 0);
	return ans;
};
