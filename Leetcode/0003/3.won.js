/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
  const map = new Map();
  let maxLength = 0;
  let start = -1;
  for (let i = 0; i < s.length; i++) {
    const target = s[i];
    if (map.has(target) && map.get(target) > start) {
      start = map.get(target);
    }
    maxLength = Math.max(maxLength, i - start);
    map.set(target, i);
  }
  return maxLength;
};
