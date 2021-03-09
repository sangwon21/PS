/**
 * @param {string[]} words
 * @param {number} k
 * @return {string[]}
 */
var topKFrequent = function (words, k) {
	const items = [];

	const leftChild = (idx) => items[idx * 2 + 1];
	const rightChild = (idx) => items[idx * 2 + 2];

	const parent = (idx) => items[Math.floor((idx - 1) / 2)];

	const swap = (idx1, idx2) => {
		[items[idx1], items[idx2]] = [items[idx2], items[idx1]];
	};

	const bubbleDown = () => {
		let index = 0;
		let smallerIndex = 0;

		while (
			(leftChild(index) && compare(leftChild(index), items[index])) ||
			(rightChild(index) && compare(rightChild(index), items[index]))
		) {
			smallerIndex = index * 2 + 1;

			if (rightChild(index) && compare(rightChild(index), items[smallerIndex])) {
				smallerIndex = index * 2 + 2;
			}

			swap(smallerIndex, index);
			index = smallerIndex;
		}
	};

	const bubbleUp = () => {
		let index = items.length - 1;

		while (parent(index) && !compare(parent(index), items[index])) {
			const parentIdx = Math.floor((index - 1) / 2);
			swap(index, parentIdx);
			index = parentIdx;
		}
	};

	const push = (item) => {
		items[items.length] = item;
		bubbleUp();
	};

	const pop = () => {
		const item = items[0];
		swap(0, items.length - 1);
		items.pop();
		bubbleDown();
		return item;
	};

	const compare = (a, b) => {
		if (a.freq === b.freq) {
			return a.str.localeCompare(b.str) < 0;
		}

		return a.freq > b.freq;
	};

	const map = new Map();

	for (let i = 0; i < words.length; i++) {
		const word = words[i];
		if (map.has(word)) {
			const count = map.get(word);
			map.set(word, count + 1);
		} else {
			map.set(word, 1);
		}
	}

	for (const [key, value] of map) {
		push({ freq: value, str: key });
	}
	const ans = [];

	while (k--) {
		ans.push(pop().str);
	}

	return ans;
};
