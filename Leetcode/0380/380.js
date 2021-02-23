/**
 * Initialize your data structure here.
 */
var RandomizedSet = function() {
    this.map = new Map();
    this.array = [];
};

/**
 * Inserts a value to the set. Returns true if the set did not already contain the specified element. 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.insert = function(val) {
    if (this.map.has(val)) {
        return false;
    }
    
    this.map.set(val, this.array.length);
    this.array.push(val);
    
    return true;
};

/**
 * Removes a value from the set. Returns true if the set contained the specified element. 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.remove = function(val) {
    if (!this.map.has(val)) {
        return false;
    }
    
    const index = this.map.get(val);
    
    const lastElement = this.array[this.array.length - 1];
    this.array[index] = lastElement;
    
    this.map.set(lastElement, index);
    this.map.delete(val);
    this.array.pop();
    return true;
};

/**
 * Get a random element from the set.
 * @return {number}
 */
RandomizedSet.prototype.getRandom = function() {
    return this.array[Math.floor(Math.random() * this.array.length)];
};

/** 
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */