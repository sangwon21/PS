function solution(n, computers) {
  targetComputers = computers;
  targetComputerCounts = n;

  for (let i = 0; i < n; i++) {
    computerPoints.push(false);
  }

  for (let j = 0; j < n; j++) {
    if (!computerPoints[j]) {
      networks += 1;
      dfs(j);
    }
  }
  return networks;
}

const computerPoints = [];
let targetComputers = [];
let targetComputerCounts = 0;
let networks = 0;

function dfs(computerStart) {
  if (computerPoints[computerStart]) {
    return;
  }

  computerPoints[computerStart] = true;

  for (let i = 0; i < targetComputerCounts; i++) {
    if (i === computerStart) {
      continue;
    }

    if (targetComputers[computerStart][i] === 1) {
      if (computerPoints[i] === false) {
        dfs(i);
      }
    }
  }
}
