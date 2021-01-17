/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function (n) {
    const result = [];

    const helper = (str, open, close, max) => {
        if (open + close >= max) {
            if (open + close === max) {
                result.push(str);
                return;
            }
            return;
        }

        if (open < parseInt(max / 2)) {
            helper(str + "(", open + 1, close, max);
        }
        if (close < open) {
            helper(str + ")", open, close + 1, max);
        }
    };

    helper("", 0, 0, 2 * n);
    return result;
};
