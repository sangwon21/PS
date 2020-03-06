function solution(s) {
  var answer = true;

  const stack = [];
  const targetString = [...s];

  for (let i = 0; i < targetString.length; i++) {
    if (targetString[i] === ")") {
      if (!stack.length) {
        return false;
      }
      stack.pop();
      continue;
    }
    stack.push(targetString[i]);
  }

  if (stack.length) {
    return false;
  }

  return true;
}
