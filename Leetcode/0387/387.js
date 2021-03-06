/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function (s) {
	const map = new Map();
	for (let i = 0; i < s.length; i++) {
		const letter = s[i];
		if (map.has(letter)) {
			map.set(letter, { duplicated: true });
		} else {
			map.set(letter, { duplicated: false, idx: i });
		}
	}
	let ans = Number.POSITIVE_INFINITY;
	for (const [key, { duplicated, idx }] of map) {
		if (!duplicated) {
			ans = Math.min(ans, idx);
		}
	}
	if (isFinite(ans)) {
		return ans;
	}
	return -1;
};
