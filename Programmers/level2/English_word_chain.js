function solution(n, words) {
  var answer = [];
  let personIndex = 1;
  let wordIndex = 0;
  let targetWord = words[0][words[0].length - 1];
  const usedWords = {};
  usedWords[words[0]] = true;
  for (let i = 1; i < words.length; i++) {
    if (targetWord !== words[i][0] || usedWords[words[i]]) {
      return [personIndex + 1, wordIndex + 1];
    }

    targetWord = words[i][words[i].length - 1];
    usedWords[words[i]] = true;
    if (personIndex + 1 === n) {
      wordIndex += 1;
    }
    personIndex = (personIndex + 1) % n;
  }

  return [0, 0];
}
