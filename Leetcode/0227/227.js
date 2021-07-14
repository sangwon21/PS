/**
 * @param {string} s
 * @return {number}
 */
var calculate = function (s) {
  const stack = [];

  const isPlusMinus = (letter) => {
    return letter === "+" || letter === "-";
  };

  const isMultiplierDividor = (letter) => {
    return letter === "*" || letter === "/";
  };

  let isContiguousNumber = false;

  for (let i = 0; i < s.length; i++) {
    const letter = s[i];

    if (isPlusMinus(letter)) {
      stack.push(letter);
      isContiguousNumber = false;
    } else if (isMultiplierDividor(letter)) {
      const top = stack.pop();
      let index = i + 1;
      while (s[index] === " ") {
        index++;
      }
      let startIdx = index;
      let targetNumber = parseInt(s[startIdx]);
      startIdx++;

      while (
        s[startIdx] !== " " &&
        !isPlusMinus(s[startIdx]) &&
        !isMultiplierDividor(s[startIdx]) &&
        startIdx < s.length
      ) {
        targetNumber = targetNumber * 10 + parseInt(s[startIdx]);
        startIdx++;
      }
      i = startIdx - 1;
      if (letter === "*") {
        stack.push(top * parseInt(targetNumber));
      } else {
        stack.push(Math.floor(top / parseInt(targetNumber)));
      }
      isContiguousNumber = false;
    } else if (letter === " ") {
      isContiguousNumber = false;
      continue;
    } else {
      if (isContiguousNumber) {
        const prev = stack.pop();
        stack.push(prev * 10 + parseInt(letter));
      } else {
        stack.push(parseInt(letter));
        isContiguousNumber = true;
      }
    }
  }

  let sum = stack[0];
  console.log(stack);
  for (let i = 1; i < stack.length; i++) {
    const letter = stack[i];
    if (letter === "-") {
      sum -= stack[i + 1];
      i = i + 1;
    } else {
      sum += stack[i + 1];
      i = i + 1;
    }
  }

  return sum;
};
