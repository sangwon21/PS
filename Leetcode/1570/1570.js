/**
 * @param {number[]} nums
 * @return {SparseVector}
 */
var SparseVector = function(nums) {
    this.nonZeroes = new Map();
    
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== 0) {
            this.nonZeroes.set(i, nums[i]);
        }
    }
};

// Return the dotProduct of two sparse vectors
/**
 * @param {SparseVector} vec
 * @return {number}
 */
SparseVector.prototype.dotProduct = function(vec) {
    let result = 0;
    
    for (const [idx, value] of vec.nonZeroes) {
        if (this.nonZeroes.has(idx)) {
            result += this.nonZeroes.get(idx) * value;
        }
    }
    
    return result;
};

// Your SparseVector object will be instantiated and called as such:
// let v1 = new SparseVector(nums1);
// let v2 = new SparseVector(nums2);
// let ans = v1.dotProduct(v2);