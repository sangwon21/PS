class Solution {
public:
    void reverseString(vector<char>& s) {
        
        if(s.size() == 0)
        {
            return;
        }
        std::vector<char>::iterator start = s.begin();
        std::vector<char>::iterator end = s.end() - 1;
        
        while(start < end)
        {
            char tmp = *start;
            *start = *end;
            *end = tmp;
            start++;
            end--;
        }
    }
};