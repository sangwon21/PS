#include <string>

class Solution {
public:
    bool bWatch[10];
    int watches[10] = {1,2,4,8,1,2,4,8,16,32};

    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        
        backtracking(res, 0, 0,num);
        return res;
    }
    
    void backtracking(vector<string> &res, int watch, int start ,int num)
    {
        if(watch == num)
        {
            int sHour = 0;
            int sMinute = 0;
            
            for(int i = 0; i < 4; i++)
            {
                if(bWatch[i])
                {
                    sHour += watches[i];
                }
            }
            
            for(int i = 4; i < 10; i++)
            {
                if(bWatch[i])
                {
                    sMinute += watches[i];
                }
            }
            for(int i = 0; i< 10; i++)
            {
                std::cout<<bWatch[i]<<' ';
            }
            std::cout<<std::endl;
            
            if(sMinute >= 60)
            {
                return;
            }
            if(sHour >= 12)
            {
                return;
            }
            string minuteForString;
            if(sMinute < 10)
            {
                minuteForString = "0" + std::to_string(sMinute);
            }
            else
            {
                minuteForString = std::to_string(sMinute);
            }
            string s = std::to_string(sHour) + ":" + minuteForString;
            res.push_back(s);
            return;
        }
        
        if(start >= 10)
            return;
        
          
        bWatch[start] = true;
        backtracking(res, watch + 1, start + 1,num);
        bWatch[start] = false;
        backtracking(res, watch, start + 1 ,num);    
    }
};