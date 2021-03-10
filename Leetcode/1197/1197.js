/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var minKnightMoves = function (x, y) {
	const dx = [-2, -1, 1, 2, 2, 1, -1, -2];
	const dy = [1, 2, 2, 1, -1, -2, -2, -1];

	const hasVisited = new Set();

	const q = [];

	q.push({ tX: 0, tY: 0, moves: 0 });

	while (q.length !== 0) {
		const { tX, tY, moves } = q.shift();

		if (tX === x && tY === y) {
			return moves;
		}

		for (let i = 0; i < 8; i++) {
			const nX = tX + dx[i];
			const nY = tY + dy[i];

			if (hasVisited.has(`${nX},${nY}`)) {
				continue;
			}

			q.push({ tX: nX, tY: nY, moves: moves + 1 });
			hasVisited.add(`${nX},${nY}`);
		}
	}

	return 0;
};
