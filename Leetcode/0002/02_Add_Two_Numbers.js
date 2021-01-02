/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let l1Ptr = l1;
    let l2Ptr = l2;
    let carry = 0;
    let head = null;
    let headPtr = head;
    
    while (l1Ptr !== null && l2Ptr !== null) {
        if (head === null) {
            let value = l1Ptr.val + l2Ptr.val;
            if (value >= 10) {
                carry = 1;
                value -= 10;
            }
            head = new ListNode(value, null);
            headPtr = head;
        } else {
            let value = l1Ptr.val + l2Ptr.val + carry;
            carry = 0;
            if (value >= 10) {
                carry = 1;
                value -= 10;
            }
            headPtr.next = new ListNode(value, null);
            headPtr = headPtr.next;
        }
        
        l1Ptr = l1Ptr.next;
        l2Ptr = l2Ptr.next;
    }
    
    while (l1Ptr !== null) {
        if (head === null) {
            let value = l1Ptr.val + carry;
            if (value >= 10) {
                carry = 1;
                value -= 10;
            }
            head = new ListNode(value, null);
        } else {
            let value = l1Ptr.val + carry;
            carry = 0;
            if (value >= 10) {
                carry = 1;
                value -= 10;
            }
            headPtr.next = new ListNode(value, null);
            headPtr = headPtr.next;
        }
        l1Ptr = l1Ptr.next;
    }
    
    while (l2Ptr !== null) {
        if (head === null) {
            let value = l2Ptr.val + carry;
            if (value >= 10) {
                carry = 1;
                value -= 10;
            }
            head = new ListNode(value, null);
        } else {
            let value = l2Ptr.val + carry;
            carry = 0;
            if (value >= 10) {
                carry = 1;
                value -= 10;
            }
            headPtr.next = new ListNode(value, null);
            headPtr = headPtr.next;
        }
        l2Ptr = l2Ptr.next;
    }
    
    if (carry === 1) {
        headPtr.next = new ListNode(carry, null);
        headPtr = headPtr.next;
    }
    
    return head;
};