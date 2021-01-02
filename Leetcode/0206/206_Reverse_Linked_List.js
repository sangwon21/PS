/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    let headPtr = head;
    let newHead = null;
    
    if (head === null) {
        return null;
    }
    
    while(headPtr != null) {
        const currentHeadPtr = headPtr;
        headPtr = headPtr.next;
        currentHeadPtr.next = newHead;
        newHead = currentHeadPtr;
    }
    
    return newHead;
};