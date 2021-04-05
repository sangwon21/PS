/**
 * @param {number} n
 * @return {number}
 */
var countArrangement = function (n) {
	const visited = new Array(n + 1).fill(false);
	let count = 0;
	const traverse = (target) => {
		if (target > n) {
			count++;
			return;
		}

		for (let i = 1; i <= n; i++) {
			if (visited[i] === false && (i % target === 0 || target % i === 0)) {
				visited[i] = true;
				traverse(target + 1);
				visited[i] = false;
			}
		}
	};

	traverse(1);

	return count;
};
