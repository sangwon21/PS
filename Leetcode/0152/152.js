/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
    if (nums.length === 0) {
        return 0;
    }
    let maxSoFar = nums[0];
    let minSoFar = nums[0];
    let ans = nums[0];
    
    for (let i = 1; i < nums.length; i++) {
        const target = nums[i];
        let maxNum = maxSoFar * target;
        let minNum = minSoFar * target;
        
        maxSoFar = Math.max(maxNum, minNum, target);
        minSoFar = Math.min(maxNum, minNum, target);
        
        ans = Math.max(maxSoFar, ans);
    }
    return ans;
};