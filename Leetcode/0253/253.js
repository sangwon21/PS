/**
 * @param {number[][]} intervals
 * @return {number}
 */
var minMeetingRooms = function (intervals) {
	const items = [];

	const parent = (idx) => items[Math.floor((idx - 1) / 2)];
	const leftChild = (idx) => items[idx * 2 + 1];
	const rightChild = (idx) => items[idx * 2 + 2];
	const swap = (a, b) => {
		[items[a], items[b]] = [items[b], items[a]];
	};

	const bubbleUp = () => {
		let idx = items.length - 1;

		while (parent(idx) && !compare(parent(idx), items[idx])) {
			swap(Math.floor((idx - 1) / 2), idx);
			idx = Math.floor((idx - 1) / 2);
		}
	};

	const bubbleDown = () => {
		let idx = 0;
		let smallerIdx = 0;

		while (
			(leftChild(idx) && compare(leftChild(idx), items[idx])) ||
			(rightChild(idx) && compare(rightChild(idx), items[idx]))
		) {
			smallerIdx = idx * 2 + 1;
			if (rightChild(idx) && compare(rightChild(idx), items[smallerIdx])) {
				smallerIdx = idx * 2 + 2;
			}

			swap(smallerIdx, idx);
			idx = smallerIdx;
		}
	};

	const push = (element) => {
		items.push(element);

		bubbleUp();
	};

	const pop = () => {
		const target = items[0];
		swap(0, items.length - 1);
		items.pop();
		bubbleDown();

		return target;
	};

	const compare = (a, b) => {
		return a < b;
	};

	intervals.sort((a, b) => a[0] - b[0]);

	push(intervals[0][1]);

	for (let i = 1; i < intervals.length; i++) {
		const compareTarget = items[0];

		if (intervals[i][0] >= compareTarget) {
			pop();
		}

		push(intervals[i][1]);
	}

	return items.length;
};
