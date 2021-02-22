/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function(s) {
    
    const map = new Map();
    
    const decodeString = (s, idx) => {
        if (map.has(idx)) {
            return map.get(idx);
        }
        
        if (idx >= s.length) {
            return 1;
        }
        
        if (s[idx] === '0') {
            return 0;
        }
        
        if (idx === s.length - 1) { 
            return 1;
        }
        
        let res = decodeString(s, idx + 1);
        if (parseInt(s.substr(idx, 2)) <= 26) {
            res += decodeString(s, idx + 2);
        }
        
        map.set(idx, res);
        
        return res;
    }
    
    return decodeString(s, 0);
};