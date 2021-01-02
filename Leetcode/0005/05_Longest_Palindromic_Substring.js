/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function (s) {
  if (s.length <= 1 || s.split("").reverse().join("") === s) {
    return s;
  }
  const { length } = s;
  let maxString = "";
  const expandStringToLimits = (startIdx, endIdx) => {
    let localStartIdx = startIdx;
    let localEndIdx = endIdx;
    let result = 0;
    let returnStr = "";
    while (
      localStartIdx >= 0 &&
      localEndIdx < length &&
      s[localStartIdx] === s[localEndIdx]
    ) {
      result = localEndIdx - localStartIdx + 1;
      returnStr = s.slice(localStartIdx, localEndIdx + 1);
      localStartIdx--;
      localEndIdx++;
    }
    return returnStr;
  };
  // 1개씩 시도
  for (let i = 0; i < length; i++) {
    const result = expandStringToLimits(i, i);
    if (maxString.length < result.length) {
      maxString = result;
    }
  }
  // 2개씩 시도
  for (let i = 0; i < length; i++) {
    const result = expandStringToLimits(i, i + 1);
    if (maxString.length < result.length) {
      maxString = result;
    }
  }
  return maxString;
};
