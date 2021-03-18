/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {number[]}
 */
var findOrder = function (numCourses, prerequisites) {
	const graph = [];
	const inDegrees = new Array(numCourses).fill(0);

	for (let i = 0; i < numCourses; i++) {
		const arr = [];
		graph.push(arr);
	}

	for (let i = 0; i < prerequisites.length; i++) {
		const [a, b] = prerequisites[i];
		graph[b].push(a);
		inDegrees[a]++;
	}

	const q = [];

	for (let i = 0; i < numCourses; i++) {
		if (inDegrees[i] === 0) {
			q.push(i);
		}
	}

	let visited = 0;
	const ans = [];
	while (q.length !== 0) {
		const next = q.pop();
		ans.push(next);
		visited++;
		for (let i = 0; i < graph[next].length; i++) {
			const to = graph[next][i];
			inDegrees[to]--;
			if (inDegrees[to] === 0) {
				q.push(to);
			}
		}
	}

	return visited === numCourses ? ans : [];
};
