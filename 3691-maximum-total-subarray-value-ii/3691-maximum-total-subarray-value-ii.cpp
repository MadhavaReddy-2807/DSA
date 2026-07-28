class Solution {
public:
vector<pair<int,int>>seg;
 void build(vector<int>&nums,int i,int l,int r)
 {
    if(l==r)
    {
        seg[i]={nums[l],nums[r]};
        return;
    }
    int mid=(l+r)/2;
    build(nums,2*i+1,l,mid);
    build(nums,2*i+2,mid+1,r);
    seg[i]={max(seg[2*i+1].first,seg[2*i+2].first),min(seg[2*i+2].second,seg[2*i+1].second)};
 }
 pair<int,int>query(int l,int r,int nodel,int noder,int i)
 {
     if(l>noder||r<nodel)
     {
        return {INT_MIN,INT_MAX};
     }
     if(l<=nodel&&noder<=r)
     {
        return seg[i];
     }
     else
     {
        int mid=(nodel+noder)/2;
        auto left=query(l,r,nodel,mid,2*i+1);
        auto right=query(l,r,mid+1,noder,2*i+2);
        return {max(left.first,right.first),min(left.second,right.second)};
     }
 }
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        seg.resize(4*n,{INT_MIN,INT_MAX});
        build(nums,0,0,n-1);
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<n;i++)
        {
            auto result=query(i,n-1,0,n-1,0);
            pq.push({result.first-result.second,{i,n-1}});
            cout<<i<<" "<<result.first-result.second<<endl;
        }
        long long  res=0;
        while(pq.size()!=0&&k!=0)
        {
            auto x=pq.top();
            long long size=x.first;
            int l=x.second.first;
            int r=x.second.second;
            pq.pop();
            k--;
            res+=size;
             if(l!=r)
             {
               auto result=query(l,r-1,0,n-1,0);
               pq.push({result.first-result.second,{l,r-1}});
             }
        }
        return res;
        
    }
};