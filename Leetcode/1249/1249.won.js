/**
 * @param {string} s
 * @return {string}
 */
var minRemoveToMakeValid = function (s) {
	const strStack = [];
	const parenthesisStack = [];

	const tmpStack = [];

	for (let i = 0; i < s.length; i++) {
		const target = s[i];

		if (target === "(") {
			parenthesisStack.push(strStack.length);
		} else if (target === ")") {
			if (parenthesisStack.length === 0) {
				continue;
			}
			parenthesisStack.pop();
		}
		strStack.push(target);
	}

	let parenthesisPointer = 0;
	if (parenthesisStack.length !== 0) {
		for (let i = 0; i < strStack.length; i++) {
			if (i === parenthesisStack[parenthesisPointer]) {
				parenthesisPointer++;
				continue;
			}
			tmpStack.push(strStack[i]);
		}
	} else {
		return strStack.join("");
	}

	return tmpStack.join("");
};
