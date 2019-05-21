#include <algorithm>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        nums1.erase( unique( nums1.begin(), nums1.end() ), nums1.end() );
        
        int size = nums2.size();
        vector<int> ans;
        if(size == 0)
        {
            return ans;
        }
        
        std::sort(nums2.begin(), nums2.end());
                       
        for(auto tmp: nums1)
        {
            if(binarySearch(0, size - 1, tmp, nums2))
            {
                ans.push_back(tmp);
            }
        }
        
        return ans;
    }
    
    bool binarySearch(int left, int right, int num, vector<int>& num2)
    {
        if(left <= right)
        {
            int mid = (left + right) / 2;
            if(num2[mid] == num)
            {
                return true;
            }
            if(num2[mid] > num)
            {
                return binarySearch(left, mid - 1, num, num2);
            }
            else
            {
                return binarySearch(mid + 1, right, num, num2);
            }
        }
        return false;
    }
};