class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>result;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int x;
        for(auto it:mp)
        {
            if(it.second==2)
            {
                x=it.first;
            }
        }
        result.push_back(x);
        for(int i=1;i<=nums.size();i++)
        {
            if(!mp[i])
            {
                result.push_back(i);
            }
        }
        return result;
    }
};