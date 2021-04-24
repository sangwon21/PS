/**
 * @param {string[][]} accounts
 * @return {string[][]}
 */
var accountsMerge = function (accounts) {
	const DSU = (size) => {
		const parent = new Array(size + 1);

		for (let i = 0; i <= size; i++) {
			parent[i] = i;
		}

		const find = (x) => {
			if (parent[x] !== x) {
				parent[x] = find(parent[x]);
			}
			return parent[x];
		};

		const union = (x, y) => {
			let foundX = find(x);
			let foundY = find(y);
			if (foundX != foundY) {
				parent[foundY] = foundX;
			}
		};

		return {
			union,
			find
		};
	};

	const { union, find } = DSU(10000);

	const emailToName = new Map();
	const emailToId = new Map();
	let id = 0;
	for (const account of accounts) {
		let name = "";

		for (const email of account) {
			if (name === "") {
				name = email;
				continue;
			}

			emailToName.set(email, name);
			if (!emailToId.has(email)) {
				emailToId.set(email, id++);
			}
			union(emailToId.get(account[1]), emailToId.get(email));
		}
	}
	const ans = new Map();

	for (const email of emailToName.keys()) {
		const idx = find(emailToId.get(email));
		if (!ans.has(idx)) {
			ans.set(idx, [email]);
		} else {
			ans.get(idx).push(email);
		}
	}
	const res = [];

	for (const emails of ans.values()) {
		emails.sort();
		emails.unshift(emailToName.get(emails[0]));
		res.push([...emails]);
	}

	return res;
};
