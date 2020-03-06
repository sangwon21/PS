function solution(arrangement) {
  let answer = 0;

  let stack = [];

  let sticks = [...arrangement];
  let isRazor = false;

  for (let i = 0; i < sticks.length; i++) {
    if (sticks[i] === "(") {
      stack.push(sticks[i]);
      isRazor = false;
      continue;
    }
    if (isRazor === true) {
      stack.pop();
      answer += 1;
      continue;
    }
    stack.pop();
    answer += stack.length;
    isRazor = true;
  }

  return answer;
}
