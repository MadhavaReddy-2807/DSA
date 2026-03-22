#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
class Solution {
public:
    vector<vector<int>>seg;
    void build(int l,int r,int i,vector<int>&nums)
    {
        int n=nums.size();
        int LOG=__lg(n)+1;
        seg.assign(LOG,vector<int>(n));
        seg[0]=nums;
        for(int j=1;j<LOG;j++)
            for(int i=0;i+(1<<j)<=n;i++)
                seg[j][i]=seg[j-1][i]|seg[j-1][i+(1<<(j-1))];
    }
    int range(int l,int r,int start,int end,int index)
    {
        int k=__lg(r-l+1);
        return seg[k][l]|seg[k][r-(1<<k)+1];
    }
  
    long long countGoodSubarrays(vector<int>& nums) {
        int n=nums.size();
        build(0,n-1,0,nums);
        vector<int>prev(n,-1);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.count(nums[i]))
            {
                prev[i]=mp[nums[i]];
            }
                mp[nums[i]]=i;  
        }
        long long res=0;
        for(int i=0;i<n;i++)
            {
                int l=i;
                int r=n-1;
                int rans=1;
                int lans=1;
                while(l<=r)
                    {
                        int mid=(l+r)/2;
                        if(range(i,mid,0,n-1,0)==nums[i])
                        {
                            rans=(mid-i+1);
                            l=mid+1;
                        }
                        else
                        {
                            r=mid-1;
                        }
                    }
                 r=i;
                 l=prev[i]+1;
                while(l<=r)
                    {
                        int mid=(l+r)/2;
                        if(range(mid,i,0,n-1,0)==nums[i])
                        {
                            lans=i-mid+1;
                            r=mid-1;
                        }
                        else
                        {
                            l=mid+1;
                        }
                    }
                res+=(1LL*lans*rans);
            }
        return res;
        
    }
};