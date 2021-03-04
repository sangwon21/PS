/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function (x) {
	if (x < 0) {
		return false;
	}

	if (x === 0) {
		return true;
	}

	const arr = [];

	const divideNumber = (target) => {
		if (target < 10) {
			arr.push(target);
			return;
		}

		const remainder = target % 10;
		const nextTarget = parseInt(target / 10);

		arr.push(remainder);
		divideNumber(nextTarget);
	};

	divideNumber(x);

	let start = 0;
	let end = arr.length - 1;

	while (start < end) {
		if (arr[start] !== arr[end]) {
			return false;
		}

		start++;
		end--;
	}
	return true;
};
