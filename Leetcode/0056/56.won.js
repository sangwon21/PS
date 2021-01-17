/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function (intervals) {
    const answer = [];

    intervals.sort((a, b) => a[0] - b[0]);

    let startInterval = intervals[0];

    for (const interval of intervals) {
        if (startInterval[1] >= interval[0]) {
            startInterval[1] = Math.max(startInterval[1], interval[1]);
        } else {
            answer.push(startInterval);
            startInterval = interval;
        }
    }
    answer.push(startInterval);

    return answer;
};
