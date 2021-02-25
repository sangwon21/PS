/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    const answer = [];
    
    const column = matrix[0].length;
    const row = matrix.length;    
    let rowWise = true;
    let ascendingWise = true;
    let i = 0;
    let j = 0;
    
    
    const hasVisited = (i, j) => {
        return matrix[i][j] !== -101;
    }
    
    const isValid = (i, j) => {
         return 0 <= i && i < matrix.length && 0 <= j && j < matrix[0].length
    }
    
    while (answer.length < row * column) {
        answer.push(matrix[i][j]);
        matrix[i][j] = -101;
        if (rowWise) {
            if (ascendingWise) {
                j++
            } else {
                j--;
            }
            if (!isValid(i, j) || !hasVisited(i,j)) {
                if (ascendingWise) {
                    j--;
                    i++;
                } else {
                    j++;
                    i--;
                }
                rowWise = false;
            }
        } else {
            if (ascendingWise) {
                i++;
            } else {
                i--;
            }
            
            if (!isValid(i,j) || !hasVisited(i,j)) {
                if (ascendingWise) {
                    i--;
                    j--
                } else {
                    i++;
                    j++
                }
                ascendingWise = !ascendingWise;
                rowWise = true;
            }
        }
    }
    
    return answer;
};