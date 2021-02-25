/**
 * @param {number[][]} isConnected
 * @return {number}
 */
var findCircleNum = function(isConnected) {
    const hasVisited = new Array(isConnected.length).fill(false);
    let result = 0;
    
    const dfs = (city) => {
        if (hasVisited[city]) {
            return;
        }
        
        hasVisited[city] = true;
        
        for (let i = 0; i < isConnected.length; i++) {
            if (isConnected[i][city] === 1 && i !== city) {
                dfs(i);
            }
        }
    }
    
    for (let i = 0; i < isConnected.length; i++) {
        if (hasVisited[i]) {
            continue;
        }
        dfs(i);
        result++;
    }
    
    return result;
};