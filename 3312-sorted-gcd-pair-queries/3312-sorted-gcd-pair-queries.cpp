class Solution {
public:
int func(int mid, long long  index,vector<long long>&pairs)
{
     if(pairs[mid]>index)
     {
        return 1;
     }
     return 0;
}
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        unordered_map<int,int>freq;
        int maxi=*max_element(nums.begin(),nums.end());
        for(auto n:nums)
        {
            for(int i=1;i*i<=n;i++)
            {
                if(n%i==0)
                {
                    freq[i]++;
                if(n/i!=i)
                {
                    freq[n/i]++;
                }
                }
            }
        }
        vector<long long>pairs(maxi+1,0);
        for(int i=maxi;i>=1;i--)
        {
            long long count=freq[i];
            long long  pair=1LL*(count)*(count-1)/2;
            pairs[i]=pair;
            for(int j=2*i;j<=maxi;j+=i)
            {
                pairs[i]-=pairs[j];
            }
        }
        for(int i=1;i<pairs.size();i++)
        {
            pairs[i]+=pairs[i-1];
            // cout<<pairs[i];
        }
        vector<int>result;
        for(int i=0;i<queries.size();i++)
        {
            long long index=queries[i];
            int l=0;
            int r=pairs.size()-1;
            int ans;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(func(mid,index,pairs))
                {
                    ans=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};