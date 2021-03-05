/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function (a, b) {
	const reversedA = a.split("").reverse();
	const reversedB = b.split("").reverse();

	let idxA = 0;
	let idxB = 0;
	const result = [];
	let carry = 0;

	while (idxA < reversedA.length || idxB < reversedB.length) {
		const nextA = idxA < reversedA.length ? parseInt(reversedA[idxA]) : 0;
		const nextB = idxB < reversedB.length ? parseInt(reversedB[idxB]) : 0;

		let sum = nextA + nextB + carry;

		if (sum >= 2) {
			sum -= 2;
			carry = 1;
		} else {
			carry = 0;
		}

		result.push(sum);

		idxA++;
		idxB++;
	}

	if (carry !== 0) {
		result.push(carry);
	}

	return result.reverse().join("");
};
