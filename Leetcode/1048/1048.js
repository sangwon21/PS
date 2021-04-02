/**
 * @param {string[]} words
 * @return {number}
 */
var longestStrChain = function (words) {
	const dp = new Array(words.length);
	dp[0] = 1;
	let max = 1;

	words.sort((a, b) => a.length - b.length);

	const test = (word, cmp) => {
		for (let i = 0; i < word.length; i++) {
			const tmp = word.substring(0, i);
			const tmp2 = word.substr(i + 1);
			if (tmp + tmp2 === cmp) {
				return true;
			}
		}

		return false;
	};

	for (let i = 1; i < words.length; i++) {
		const word = words[i];
		dp[i] = 1;
		for (let j = i - 1; j >= 0; j--) {
			const cmp = words[j];
			if (test(word, cmp)) {
				dp[i] = Math.max(dp[i], dp[j] + 1);
			}
		}
		max = Math.max(dp[i], max);
	}

	return max;
};
