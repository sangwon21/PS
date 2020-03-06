function solution(s) {
  var answer = "";
  const numbers = s.split(" ").map(char => parseInt(char));
  let maxNumber = numbers[0];
  let minNumber = numbers[0];

  for (let i = 0; i < numbers.length; i++) {
    if (numbers[i] > maxNumber) {
      maxNumber = numbers[i];
    }
    if (numbers[i] < minNumber) {
      minNumber = numbers[i];
    }
  }
  return `${minNumber} ${maxNumber}`;
}
