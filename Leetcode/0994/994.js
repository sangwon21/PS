/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function (grid) {
	const hasVisited = [];

	const rottenOranges = [];

	for (let i = 0; i < grid.length; i++) {
		const newArr = [];
		for (let j = 0; j < grid[0].length; j++) {
			if (grid[i][j] === 2) {
				rottenOranges.push([i, j, 0]);
			}
			newArr.push(false);
		}
		hasVisited.push(newArr);
	}

	const dx = [-1, 1, 0, 0];
	const dy = [0, 0, -1, 1];

	const isValid = (i, j) => {
		return 0 <= i && i < grid.length && 0 <= j && j < grid[0].length;
	};

	const q = [...rottenOranges];
	let maxDay = 0;

	while (q.length > 0) {
		const [curI, curJ, day] = q.shift();

		if (hasVisited[curI][curJ]) {
			continue;
		}

		hasVisited[curI][curJ] = true;
		grid[curI][curJ] = 2;
		maxDay = maxDay < day ? day : maxDay;

		for (let dir = 0; dir < 4; dir++) {
			const nextI = curI + dx[dir];
			const nextJ = curJ + dy[dir];

			if (isValid(nextI, nextJ) && hasVisited[nextI][nextJ] === false) {
				if (grid[nextI][nextJ] === 1) {
					q.push([nextI, nextJ, day + 1]);
				}
			}
		}
	}

	for (let i = 0; i < grid.length; i++) {
		for (let j = 0; j < grid[0].length; j++) {
			if (grid[i][j] === 1) {
				return -1;
			}
		}
	}

	return maxDay;
};
