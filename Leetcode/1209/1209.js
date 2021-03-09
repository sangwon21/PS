/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var removeDuplicates = function (s, k) {
	const stack = [];
	let duplicated = 0;

	for (let i = 0; i < s.length; i++) {
		const letter = s[i];

		if (stack.length === 0) {
			stack.push({ letter, freq: 1 });
			continue;
		}
		const top = stack[stack.length - 1];

		if (top.letter === letter) {
			if (top.freq === k - 1) {
				stack.pop();
				continue;
			}
			top.freq = top.freq + 1;
		} else {
			stack.push({ letter, freq: 1 });
		}
	}
	const ans = [];
	for (let i = 0; i < stack.length; i++) {
		const { freq, letter } = stack[i];

		for (let j = 0; j < freq; j++) {
			ans.push(letter);
		}
	}
	return ans.join("");
};
