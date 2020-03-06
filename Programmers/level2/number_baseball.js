function solution(baseball) {
  gBaseball = baseball;

  helper([], 0);
  return answer;
}

let answer = 0;
let gBaseball = null;
const used = [false, false, false, false, false, false, false, false, false];

function check(candidateNumber, judge) {
  let strike = 0;
  let ball = 0;

  for (let i = 0; i < judge.length; i++) {
    for (let j = 0; j < candidateNumber.length; j++) {
      if (candidateNumber[j] === judge[i]) {
        if (i === j) {
          strike++;
        } else {
          ball++;
        }
      }
    }
  }
  return [strike, ball];
}

function helper(numbers, index) {
  if (index === 3) {
    for (let i = 0; i < gBaseball.length; i++) {
      const [strike, ball] = check(numbers.join(""), gBaseball[i][0] + "");
      if (strike !== gBaseball[i][1] || ball !== gBaseball[i][2]) {
        return;
      }
    }
    answer++;
    return;
  }
  for (let i = 0; i < 9; i++) {
    if (used[i] === false) {
      used[i] = true;
      numbers[index] = i + 1;
      helper(numbers, index + 1);
      used[i] = false;
    }
  }
}
