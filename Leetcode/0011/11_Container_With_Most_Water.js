/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let leftPtr = 0;
    let rightPtr = height.length - 1;
    let maxArea = 0;
    
    
    while (leftPtr < rightPtr) {
        
        const currentHeight = Math.min(height[leftPtr], height[rightPtr]);
        
        const currentArea = currentHeight * (rightPtr - leftPtr)

        if (maxArea < currentArea) {
            maxArea = currentArea;
        }
        
        if (height[leftPtr] < height[rightPtr]) {
            leftPtr += 1;
        } else {
            rightPtr -= 1;
        }
    }
    
    return maxArea;
};