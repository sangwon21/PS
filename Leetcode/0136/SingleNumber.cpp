class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int sum = 0;

        for (int num : nums)
        {
            sum ^= num;
        }

        return sum;
    }
};