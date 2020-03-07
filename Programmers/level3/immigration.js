function solution(n, times) {
  let minTime = 1;
  let maxTime = times[times.length - 1] * n;
  let answer = maxTime;

  while (minTime <= maxTime) {
    const midTime = parseInt((minTime + maxTime) / 2);

    let sum = 0;

    for (let i = 0; i < times.length; i++) {
      sum += parseInt(midTime / times[i]);
    }

    if (sum >= n) {
      if (midTime < answer) {
        answer = midTime;
      }

      maxTime = midTime - 1;
      continue;
    }
    minTime = midTime + 1;
  }
  return answer;
}
