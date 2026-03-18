class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
      vector<int>bits(31,0);
        for(int i=0;i<nums.size();i++)
            {
                for(int bit=30;bit>=0;bit--)
                    {
                        if((nums[i]>>bit)&1)
                        {
                            bits[bit]++;
                        }
                    }
            }
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--)
            {
                int res=0;
                for(int bit=maximumBit-1;bit>=0;bit--)
                    {
                       if(bits[bit]%2==0)
                       {
                           res=res|(1<<bit);
                       }
                    }
                ans.push_back(res);
                 for(int bit=30;bit>=0;bit--)
                    {
                        if((nums[i]>>bit)&1)
                        {
                            bits[bit]--;
                        }
                    }
                
            }
        return ans;
    }
};