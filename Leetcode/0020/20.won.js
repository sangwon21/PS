/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  if (s.length % 2 === 1) {
    return false;
  }

  const stack = [];
  const parenthesis = {
    "}": "{",
    ")": "(",
    "]": "[",
  };

  for (let i = 0; i < s.length; i++) {
    const targetLetter = s[i];

    if (targetLetter === "(" || targetLetter === "{" || targetLetter === "[") {
      stack.push(targetLetter);
    } else {
      const compareLetter = stack.pop();
      if (compareLetter !== parenthesis[targetLetter]) {
        return false;
      }
    }
  }

  if (stack.length !== 0) {
    return false;
  }

  return true;
};
