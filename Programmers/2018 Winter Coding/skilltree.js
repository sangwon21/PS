function solution(skill, skill_trees) {
    var answer = 0;
    for(let i = 0; i < skill_trees.length; i++)
        {
            let currentSkill = skill_trees[i];
            let indexOfArray = [];
            
            for(let j = 0; j < currentSkill.length; j++)
                {
                    let idx = skill.indexOf(currentSkill[j]);
                    if(idx !== -1)
                        {
                            indexOfArray.push(idx);
                        }
                }
            let judge = false;
            console.log(indexOfArray)
            if(indexOfArray.length === 0)
                {
                    answer += 1;
                    continue;
                }
            if(indexOfArray[0] !== 0)
                {
                    continue;
                }
            for(let j = 0; j < indexOfArray.length - 1; j++)
                {
                    if(indexOfArray[j] > indexOfArray[j + 1]) continue;
                    if(indexOfArray[j] + 1 !== indexOfArray[j + 1])
                        {
                            judge = true;
                            break;
                        }
                }
            if(judge)
                {
                    continue;
                }
            answer += 1;
        }
    return answer;
}