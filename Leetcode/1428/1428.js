/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * function BinaryMatrix() {
 *     @param {integer} row, col
 *     @return {integer}
 *     this.get = function(row, col) {
 *         ...
 *     };
 *
 *     @return {[integer, integer]}
 *     this.dimensions = function() {
 *         ...
 *     };
 * };
 */

/**
 * @param {BinaryMatrix} binaryMatrix
 * @return {number}
 */
var leftMostColumnWithOne = function(binaryMatrix) {
    const [row, column] = binaryMatrix.dimensions();
    
    let ans = column;
    
    for (let i = 0; i < row; i++) {
        let lo = 0;
        let hi = column - 1;
        while (lo < hi) {
            const mid = lo + parseInt((hi - lo) / 2);
            
            if (binaryMatrix.get(i, mid) === 1) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        if (binaryMatrix.get(i, lo) === 1) {
            ans = ans > lo ? lo : ans;
        }
    }
    
    return ans === column ? -1 : ans;
};