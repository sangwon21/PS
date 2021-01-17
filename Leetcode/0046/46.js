/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function (nums) {
    const hasVisited = Array(nums.length).fill(false);

    const ans = [];

    const dfs = (tmpArr) => {
        if (tmpArr.length === nums.length) {
            ans.push([...tmpArr]);
            return;
        }

        for (let i = 0; i < nums.length; i++) {
            if (!hasVisited[i]) {
                hasVisited[i] = true;
                tmpArr.push(nums[i]);
                dfs(tmpArr);
                tmpArr.pop();
                hasVisited[i] = false;
            }
        }
    };

    dfs([]);

    return ans;
};
