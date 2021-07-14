/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  const shortestLength = strs.reduce(
    (acc, cur) => Math.min(acc, cur.length),
    201
  );

  let prefix = "";

  for (let i = 0; i < shortestLength; i++) {
    const target = strs[0][i];

    for (let j = 1; j < strs.length; j++) {
      if (target !== strs[j][i]) {
        return prefix;
      }
    }

    prefix += target;
  }

  return prefix;
};
