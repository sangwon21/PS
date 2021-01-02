/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function (strs) {
  const anagrams = {};

  strs.forEach((str) => {
    const sortedStr = str.split("").sort().join("");
    if (!anagrams[sortedStr]) {
      anagrams[sortedStr] = [str];
      return;
    }
    anagrams[sortedStr].push(str);
  });

  const ans = [];

  for (anagram in anagrams) {
    ans.push(anagrams[anagram]);
  }
  return ans;
};
