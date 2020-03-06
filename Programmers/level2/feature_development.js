function solution(progresses, speeds) {
  var answer = [];
  let i = 0;
  while (progresses.length != 0) {
    for (let k = 0; k < progresses.length; k++) {
      progresses[k] += speeds[k];
    }

    if (progresses[0] >= 100) {
      while (progresses[0] >= 100) {
        progresses.shift();
        speeds.shift();
        i++;
      }
    }

    if (i !== 0) {
      answer.push(i);
      if (progresses.length === 0) {
        break;
      }
      i = 0;
    }
  }
  return answer;
}
