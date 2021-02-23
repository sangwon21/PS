class Node {
    constructor(key, value){
        this.key = key;
        this.value = value;
        this.prev = null;
        this.next = null;
    }
}

/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
    
    
    this.head = new Node(-1, -1);
    this.tail = new Node(-1, -1);
    
    this.head.next = this.tail;
    this.tail.prev = this.head;
    
    this.head.prev = null;
    this.tail.next = null;
    
    this.map = new Map();
    this.size = 0;
    this.capacity = capacity;
    
    this.addNode = (node) => {
        node.prev = this.head;
        node.next = this.head.next;
        
        this.head.next.prev = node;
        this.head.next = node;
    }
    
    this.removeNode = (node) => {
        const prev = node.prev;
        const next = node.next;
        
        prev.next = next;
        next.prev = prev;
    }
    
    this.moveToHead = (node) => {
        this.removeNode(node);
        this.addNode(node);
    }
    
    this.popTail = () => {
        const target = this.tail.prev;
        this.removeNode(target);
        return target;
    }
    
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    const node = this.map.get(key);
    if (!node) {
        return -1;
    }
    
    this.moveToHead(node);
    return node.value;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    const node = this.map.get(key);
    
    if (!node) {
        const newNode = new Node(key, value);
        this.addNode(newNode);
        
        this.map.set(key, newNode);
        
        this.size++;
        
        if (this.size > this.capacity) {
            const removedNode = this.popTail();
            this.map.delete(removedNode.key);
            this.size--;
        }
    } else {
        node.value = value;
        this.moveToHead(node);
    }
};

/** 
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */