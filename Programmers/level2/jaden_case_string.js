function solution(s) {
  var answer = "";
  const targetStrings = s.split(" ");
  answer = targetStrings
    .map(targetString => {
      targetString = targetString.toLowerCase();
      const ascii = targetString.charCodeAt(0);
      if (ascii >= 97 && ascii <= 122) {
        let tmpString = targetString.substring(1);
        tmpString = `${String.fromCharCode(ascii - 32)}${tmpString}`;
        return tmpString;
      }
      return targetString;
    })
    .join(" ");
  return answer;
}
