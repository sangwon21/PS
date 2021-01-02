/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function (head) {
  if (head === null || head.next === null) {
    return true;
  }
  let fastPtr = head;
  let slowPtr = head;
  const valueArray = [];

  while (fastPtr !== null && fastPtr.next !== null) {
    valueArray.push(slowPtr.val);

    slowPtr = slowPtr.next;
    fastPtr = fastPtr.next.next;
  }
  if (fastPtr !== null) {
    slowPtr = slowPtr.next;
  }
  while (slowPtr != null) {
    const compareValue = valueArray[valueArray.length - 1];

    if (compareValue !== slowPtr.val) {
      return false;
    }
    valueArray.pop();
    slowPtr = slowPtr.next;
  }

  if (valueArray.length !== 0) {
    return false;
  }

  return true;
};
