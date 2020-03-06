function solution(bridge_length, weight, truck_weights) {
  var answer = 0;

  function Truck(weight) {
    this.distance = 0;
    this.weight = weight;
  }

  const truckCounts = truck_weights.length;
  const onGoingTrucks = [];

  const waitingTrucks = truck_weights.map(truck_weight => {
    return new Truck(truck_weight);
  });

  const finishedTrucks = [];
  let currentTotalWeight = 0;

  while (finishedTrucks.length !== truckCounts) {
    if (
      waitingTrucks.length !== 0 &&
      currentTotalWeight + waitingTrucks[0].weight <= weight
    ) {
      currentTotalWeight += waitingTrucks[0].weight;
      onGoingTrucks.push(waitingTrucks.shift());
    }

    onGoingTrucks.forEach(onGoingTruck => onGoingTruck.distance++);

    if (onGoingTrucks[0].distance === bridge_length) {
      currentTotalWeight -= onGoingTrucks[0].weight;
      finishedTrucks.push(onGoingTrucks.shift());
    }

    answer++;
  }
  return answer + 1;
}
