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
var findMode = function(root) {
    let map = new Map();
    traverse(root, map);
    const ans = [];
    let maxNum = 0;
    for(let [key, value] of map) {
        if (value > maxNum) {
            while(ans.length) {
                ans.pop();
            }
            ans.push(key);
            maxNum = value;
        } else if (value === maxNum) {
            ans.push(key);
        } 
    }
    
    return ans;
};

var traverse = function(root, map) {
    if (root) {
        traverse(root.left, map);
        const counts = map.get(root.val)
        if (!counts) {
            map.set(root.val, 1);
        } else {
            map.set(root.val, counts + 1);
        }
        traverse(root.right, map);
    }
}