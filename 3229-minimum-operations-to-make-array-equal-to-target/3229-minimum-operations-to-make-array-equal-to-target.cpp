class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int prev=0;
        long long res=0;
        for(int i=0;i<nums.size();i++)
        {
            int curr=nums[i]-target[i];
            if((curr<0&&prev>0)||(curr>0&&prev<0))
            {
                res+=abs(curr);
            }
            else if(abs(curr)>abs(prev))
            {
                res+=abs(curr)-abs(prev);
            }
            prev=curr;
        }
        return res;

    }
};