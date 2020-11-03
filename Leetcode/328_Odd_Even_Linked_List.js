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
var oddEvenList = function (head) {
  let evenHead = null;
  let evenHeadPtr = null;
  let oddHead = null;
  let oddHeadPtr = null;
  let oddTurn = true;
  while (head !== null) {
    if (oddTurn) {
      if (oddHead === null) {
        oddHead = head;
        oddHeadPtr = oddHead;
      } else {
        oddHeadPtr.next = head;
        oddHeadPtr = oddHeadPtr.next;
      }
      oddTurn = false;
    } else {
      if (evenHead === null) {
        evenHead = head;
        evenHeadPtr = evenHead;
      } else {
        evenHeadPtr.next = head;
        evenHeadPtr = evenHeadPtr.next;
      }
      oddTurn = true;
    }
    head = head.next;
  }
  if (oddHeadPtr) {
    oddHeadPtr.next = null;
    oddHeadPtr.next = evenHead;
  }
  if (evenHeadPtr) {
    evenHeadPtr.next = null;
  }
  return oddHead;
};
