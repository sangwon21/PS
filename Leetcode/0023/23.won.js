/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function (lists) {
  if (lists.length === 0) {
    return null;
  }

  const arr = [];

  lists.forEach((list) => {
    let ptr = list;
    while (ptr) {
      arr.push(ptr.val);
      ptr = ptr.next;
    }
  });

  if (!arr.length) {
    return null;
  }
  arr.sort((a, b) => a - b);

  const head = new ListNode(arr[0]);
  let ptr = head;

  for (let i = 1; i < arr.length; i++) {
    const target = new ListNode(arr[i]);
    ptr.next = target;
    ptr = ptr.next;
  }

  return head;
};
