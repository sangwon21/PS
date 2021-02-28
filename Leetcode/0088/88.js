/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    let num1Idx = 0;
    let num2Idx = 0;
    let idx = 0;
    const newNums1 = [...nums1];
    
    while (num1Idx < m && num2Idx < n) {
        if (newNums1[num1Idx] < nums2[num2Idx]) {
            nums1[idx] = newNums1[num1Idx];
            num1Idx++;
        } else {
            nums1[idx] = nums2[num2Idx];
            num2Idx++;
        }
        idx++;
    }
    
    while(num1Idx < m) {
        nums1[idx] = newNums1[num1Idx];
        num1Idx++;
        idx++;
    }
    
    while(num2Idx < n) {
        nums1[idx] = nums2[num2Idx];
        num2Idx++;
        idx++;
    }
};