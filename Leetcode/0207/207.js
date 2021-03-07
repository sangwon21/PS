/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function (numCourses, prerequisites) {
	if (numCourses <= 1 || prerequisites.length === 0) {
		return true;
	}

	const hasTaken = Array(numCourses).fill(false);
	const map = {};

	for (const [pre, subject] of prerequisites) {
		if (map[pre]) {
			map[pre].push(subject);
		} else {
			map[pre] = [subject];
		}
	}
	const dfs = (start) => {
		if (hasTaken[start]) {
			return false;
		}
		hasTaken[start] = true;

		if (!map[start]) {
			hasTaken[start] = false;
			return true;
		}

		for (let i = 0; i < map[start].length; i++) {
			const next = map[start][i];
			if (dfs(next) === false) {
				return false;
			}
		}
		hasTaken[start] = false;

		return true;
	};

	for (let i = 0; i < numCourses; i++) {
		if (!dfs(i)) {
			return false;
		}
	}

	return true;
};
