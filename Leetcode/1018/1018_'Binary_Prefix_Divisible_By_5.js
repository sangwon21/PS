/**
 * @param {number[]} A
 * @return {boolean[]}
 */
var prefixesDivBy5 = function(A) {
  let binaryRemainder = 0;

  return A.map(a => {
    binaryRemainder = (binaryRemainder * 2 + a) % 5;
    return binaryRemainder === 0;
  });
};
