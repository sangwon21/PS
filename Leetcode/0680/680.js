/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function (s) {
	let start = 0;
	let end = s.length - 1;

	const isValidPalindrome = (l, r) => {
		while (l < r) {
			if (s[l] !== s[r]) {
				return false;
			}
			l++;
			r--;
		}
		return true;
	};

	while (start < end) {
		if (s[start] !== s[end]) {
			return isValidPalindrome(start + 1, end) || isValidPalindrome(start, end - 1);
		}
		start++;
		end--;
	}

	return true;
};
