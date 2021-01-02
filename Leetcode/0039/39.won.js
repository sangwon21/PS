/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function (candidates, target) {
  const sortedCandidates = candidates.sort((a, b) => a - b);

  const ans = [];

  const findCombination = (targetSum, result, idx) => {
    if (targetSum < 0) {
      return;
    }

    if (targetSum === 0) {
      ans.push([...result]);
    }
    for (let i = idx; i < sortedCandidates.length; i++) {
      if (targetSum < sortedCandidates[i]) {
        break;
      }
      result.push(sortedCandidates[i]);
      findCombination(targetSum - sortedCandidates[i], result, i);
      result.pop();
    }
  };

  findCombination(target, [], 0);

  return ans;
};
