/**
 * @param {number[]} time
 * @return {number}
 */
var numPairsDivisibleBy60 = function(time) {
    let result = 0;
    
    const remainder = time.map(element => element % 60);

    for (let i = 0; i < remainder.length - 1; i++) {
        for (let j = i + 1; j < remainder.length; j++) {
            if ((remainder[i] + remainder[j]) % 60 === 0) {
                result++;
            }
        }
    }
    
    return result;
};