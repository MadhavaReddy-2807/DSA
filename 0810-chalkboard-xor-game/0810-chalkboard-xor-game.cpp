class Solution {
public:
    bool xorGame(vector<int>& nums) {
     int x=0;
     for(auto n:nums)
     {
        x=x^n;
     }   
     if(x==0)
     {
        return true;
     }
     return nums.size()%2==0;
    }
};