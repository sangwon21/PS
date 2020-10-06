/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    const map = {};

    for (let i = 0; i < nums.length; i++) {
        if (map[target - nums[i]] === undefined) {
            map[nums[i]] = i;
        } else {
            return [map[target - parseInt(nums[i])], i];
        }
    }
};