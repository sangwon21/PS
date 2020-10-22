/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
  const answer = [];
  nums.sort();
  let targetSum = undefined;
  for (let i = 0; i < nums.length - 1; i++) {
    let tmpObj = new Map();
    let currentTargetSum = 0 - nums[i];
    if (targetSum === currentTargetSum) {
      continue;
    }
    targetSum = currentTargetSum;
    for (let j = i + 1; j < nums.length; j++) {
      if (tmpObj.has(nums[j]) === false) {
        tmpObj.set(targetSum - nums[j], 1);
      } else if (tmpObj.get(nums[j]) === 1) {
        answer.push([nums[j], targetSum - nums[j], -targetSum]);
        tmpObj.set(nums[j], 2);
      } else {
        tmpObj.set(nums[j], 2);
      }
    }
  }

  return answer;
};
