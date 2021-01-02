/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var averageOfLevels = function (root) {
    let result = [];
    traversal(root, 0, result);
    let answer = [];
    return calculateAverage(result, answer);

};

var traversal = function (root, depth, result) {
    if (root) {
        traversal(root.left, depth + 1, result);
        result.push({ val: root.val, depth });
        traversal(root.right, depth + 1, result);
    }
}

var calculateAverage = function (result, answer) {
    for (let i = 0; i < result.length; i++) {
        if (!answer[result[i].depth]) {
            answer[result[i].depth] = { sum: result[i].val, counts: 1 };
            continue;
        }
        let target = answer[result[i].depth];
        answer[result[i].depth] = { sum: parseInt(target.sum) + result[i].val, counts: parseInt(target.counts) + 1 }
    }

    return answer.reduce((acc, cur) => {
        acc.push(cur.sum / cur.counts)
        return acc;
    }, [])
}