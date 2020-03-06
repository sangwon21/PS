#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    for(unsigned int i = heights.size() - 1; i >= 1; i--)
    {
        int cmp = heights[i];
        int j;
        for(j = i - 1; j >= 0; j--)
        {
            if(cmp < heights[j])
            {
                answer.push_back(j + 1);
                break;
            }
        }
        if(j < 0)
        {
            answer.push_back(0);
        }
    }
    answer.push_back(0);
    reverse(answer.begin(), answer.end());
    return answer;
}