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
var mergeTwoLists = function (l1, l2) {
  let mergedListHead = null;
  let mergedListPtr = null;
  let l1Ptr = l1;
  let l2Ptr = l2;
  while (l1Ptr !== null && l2Ptr !== null) {
    if (l1Ptr.val < l2Ptr.val) {
      if (mergedListHead === null) {
        mergedListHead = l1Ptr;
        mergedListPtr = mergedListHead;
      } else {
        mergedListPtr.next = l1Ptr;
        mergedListPtr = mergedListPtr.next;
      }
      l1Ptr = l1Ptr.next;
    } else {
      if (mergedListHead === null) {
        mergedListHead = l2Ptr;
        mergedListPtr = mergedListHead;
      } else {
        mergedListPtr.next = l2Ptr;
        mergedListPtr = mergedListPtr.next;
      }
      l2Ptr = l2Ptr.next;
    }
  }
  while (l1Ptr !== null) {
    if (mergedListHead === null) {
      mergedListHead = l1Ptr;
      mergedListPtr = mergedListHead;
    } else {
      mergedListPtr.next = l1Ptr;
      mergedListPtr = mergedListPtr.next;
    }
    l1Ptr = l1Ptr.next;
  }
  while (l2Ptr !== null) {
    if (mergedListHead === null) {
      mergedListHead = l2Ptr;
      mergedListPtr = mergedListHead;
    } else {
      mergedListPtr.next = l2Ptr;
      mergedListPtr = mergedListPtr.next;
    }
    l2Ptr = l2Ptr.next;
  }
  return mergedListHead;
};
