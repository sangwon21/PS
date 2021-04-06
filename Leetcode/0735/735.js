/**
 * @param {number[]} asteroids
 * @return {number[]}
 */
var asteroidCollision = function (asteroids) {
	const stack = [];

	for (let i = 0; i < asteroids.length; i++) {
		let asteroid = asteroids[i];

		if (stack.length === 0) {
			stack.push(asteroid);
		} else {
			const top = stack[stack.length - 1];
			if (asteroid < 0 && top > 0) {
				while (asteroid < 0 && stack[stack.length - 1] > 0 && stack.length > 0) {
					const absAsteroid = Math.abs(asteroid);

					if (absAsteroid < stack[stack.length - 1]) {
						asteroid = 0;
						break;
					}
					const top = stack.pop();

					if (Math.abs(asteroid) === top) {
						asteroid = 0;
						break;
					}
				}
				if ((stack.length === 0 || asteroid * stack[stack.length - 1] > 0) && asteroid !== 0) {
					stack.push(asteroid);
				}
			} else {
				stack.push(asteroid);
			}
		}
	}

	return stack;
};
