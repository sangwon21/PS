/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function (digits) {
  const digitMap = {
    2: "abc",
    3: "def",
    4: "ghi",
    5: "jkl",
    6: "mno",
    7: "pqrs",
    8: "tuv",
    9: "wxyz",
  };

  const dfs = (resultStr, depth, digits, ans) => {
    if (depth === digits.length) {
      ans.push(resultStr);
      return ans;
    }

    const alphaArr = digitMap[digits[depth]].split("");

    for (let i = 0; i < alphaArr.length; i++) {
      dfs(resultStr + alphaArr[i], depth + 1, digits, ans);
    }

    return ans;
  };
  const ans = digits.length ? dfs("", 0, digits, []) : [];
  return ans;
};
