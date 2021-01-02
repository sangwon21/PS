/**
 * @param {string} paragraph
 * @param {string[]} banned
 * @return {string}
 */
var mostCommonWord = function(paragraph, banned) {
    const words = paragraph.toLowerCase().split(/\W+/);
    const map = {};
    let maxWord = '';
    let maxWordCount = 0;
    for (let i = 0; i < words.length; i++) {
        const target = words[i];
        if (target.length === 0) {
            continue;
        }
        if (banned.includes(target)) {
            continue;
        }
        if (!map[target]) {
            map[target] = 1;
            if (maxWordCount === 0) {
                maxWord = target;    
            }
            continue;
        }
        map[target] = map[target] + 1;
        if (maxWordCount < map[target]) {
            maxWordCount = map[target];
            maxWord = target;
        }
    }
    return maxWord;
};