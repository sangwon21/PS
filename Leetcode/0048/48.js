/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function (matrix) {
    for (let i = 0; i < matrix.length; i++) {
        for (let j = i; j < matrix.length; j++) {
            const tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < parseInt(matrix.length / 2); j++) {
            const tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrix.length - 1 - j];
            matrix[i][matrix.length - 1 - j] = tmp;
        }
    }

    return matrix;
};
