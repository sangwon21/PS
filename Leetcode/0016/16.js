/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function (nums, target) {
	nums.sort((a, b) => a - b);
	let diff = Infinity;
	for (let i = 0; i < nums.length && diff !== 0; i++) {
		let left = i + 1;
		let right = nums.length - 1;

		while (left < right) {
			const sum = nums[left] + nums[right] + nums[i];

			if (!isFinite(diff)) {
				diff = target - sum;
			} else if (Math.abs(target - sum) < Math.abs(diff)) {
				diff = target - sum;
			}

			if (sum < target) {
				left++;
			} else {
				right--;
			}
		}
	}
	return target - diff;
};
