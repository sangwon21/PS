/**
 * @param {string} S
 * @return {string}
 */
var reorganizeString = function (S) {
	const items = [];

	const parentIdx = (idx) => Math.floor((idx - 1) / 2);
	const leftChildIdx = (idx) => idx * 2 + 1;
	const rightChildIdx = (idx) => idx * 2 + 2;

	const parent = (idx) => items[parentIdx(idx)];
	const leftChild = (idx) => items[leftChildIdx(idx)];
	const rightChild = (idx) => items[rightChildIdx(idx)];

	const swap = (a, b) => {
		[items[a], items[b]] = [items[b], items[a]];
	};

	const bubbleUp = () => {
		let idx = items.length - 1;
		while (parent(idx) && !compare(parent(idx), items[idx])) {
			swap(parentIdx(idx), idx);

			idx = parentIdx(idx);
		}
	};

	const bubbleDown = () => {
		let idx = 0;
		let smallerIdx = 0;
		while (
			(leftChild(idx) && compare(leftChild(idx), items[idx])) ||
			(rightChild(idx) && compare(rightChild(idx), items[idx]))
		) {
			smallerIdx = leftChildIdx(idx);
			if (rightChild(idx) && compare(rightChild(idx), items[smallerIdx])) {
				smallerIdx = rightChildIdx(idx);
			}

			swap(smallerIdx, idx);

			idx = smallerIdx;
		}
	};

	const push = (element) => {
		items.push(element);
		bubbleUp();
	};

	const pop = (element) => {
		const firstElement = items[0];
		swap(0, items.length - 1);
		items.pop();
		bubbleDown();

		return firstElement;
	};

	const compare = (a, b) => {
		return a.freq >= b.freq;
	};

	const map = new Map();

	for (let i = 0; i < S.length; i++) {
		const letter = S[i];

		if (map.has(letter)) {
			const freq = map.get(letter);
			map.set(letter, freq + 1);
		} else {
			map.set(letter, 1);
		}
	}

	for (const [key, value] of map) {
		const obj = { letter: key, freq: value };
		push(obj);
	}

	let ans = "";

	while (items.length > 1) {
		const firstElement = pop();
		const secondElement = pop();

		ans += `${firstElement.letter}${secondElement.letter}`;
		firstElement.freq -= 1;
		secondElement.freq -= 1;

		if (firstElement.freq > 0) {
			push(firstElement);
		}
		if (secondElement.freq > 0) {
			push(secondElement);
		}
	}

	while (items.length > 0) {
		const element = pop();
		if (element.freq !== 1) {
			return "";
		}

		ans += element.letter;
	}

	return ans;
};
