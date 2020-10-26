/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
  const newArray = Array(nums.length).fill(1);
  let tmp = 1;
  for (let i = 0; i < nums.length; i++) {
    newArray[i] *= tmp;
    tmp *= nums[i];
  }
  tmp = 1;
  for (let i = nums.length - 1; i >= 0; i--) {
    newArray[i] *= tmp;
    tmp *= nums[i];
  }
  return newArray;
};
