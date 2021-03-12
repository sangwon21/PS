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
var addTwoNumbers = function (l1, l2) {
	const reverse = (head) => {
		if (head === null || head.next === null) {
			return head;
		}

		const reversedList = reverse(head.next);
		head.next.next = head;
		head.next = null;
		return reversedList;
	};

	let reversedL1 = reverse(l1);
	let reversedL2 = reverse(l2);

	let head = null;
	let ptr = null;
	let carry = 0;

	while (reversedL1 || reversedL2) {
		const l1Val = reversedL1 ? reversedL1.val : 0;
		const l2Val = reversedL2 ? reversedL2.val : 0;

		let sum = l1Val + l2Val + carry;
		if (sum >= 10) {
			sum -= 10;
			carry = 1;
		} else {
			carry = 0;
		}

		const curr = new ListNode(sum, null);
		if (!head) {
			head = curr;
			ptr = head;
		} else {
			ptr.next = curr;
			ptr = ptr.next;
		}

		reversedL1 = reversedL1 ? reversedL1.next : null;
		reversedL2 = reversedL2 ? reversedL2.next : null;
	}

	if (carry !== 0) {
		const curr = new ListNode(carry);
		ptr.next = curr;
	}

	return reverse(head);
};
