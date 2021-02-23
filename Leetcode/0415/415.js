/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    const num1Arr = num1.split('').reverse();
    let num1Idx = 0;
    
    const num2Arr = num2.split('').reverse();
    let num2Idx = 0;
    
    const answer = [];
    
    let carry = 0;
    while(num1Idx < num1Arr.length || num2Idx < num2Arr.length) {
        const num1Target = num1Idx >= num1Arr.length ? 0 : parseInt(num1Arr[num1Idx]);
        const num2Target = num2Idx >= num2Arr.length ? 0 : parseInt(num2Arr[num2Idx]);
        
        let sum = num1Target + num2Target + carry;
        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        
        answer.push(sum);
        num1Idx++;
        num2Idx++;
    }
    
    if (carry !== 0) {
        answer.push(carry);
    }
    
    return answer.reverse().join('');
};