class Solution {
public:
vector<int>seg;
int mod=1e9+7;
void update(int l,int r,int i,int index)
{
    if(l==r)
    {
        seg[i]++;
        return;
    }
    int mid=(l+r)/2;
    if(index<=mid)
    {
        update(l,mid,2*i+1,index);
    }
    else
    {
       update(mid+1,r,2*i+2,index);
    }
    seg[i]=seg[2*i+1]+seg[2*i+2];
}
long long query(int l,int r,int nl,int nr,int i)
{
    if(l>nr||r<nl)
    {
        return 0;
    }
    if(l<=nl&&nr<=r)
    {
        return seg[i];
    }
    int mid=(nl+nr)/2;
    int left=query(l,r,nl,mid,2*i+1);
    int right=query(l,r,mid+1,nr,2*i+2);
    return left+right;
}
    int createSortedArray(vector<int>& nums) {
      int maxi=1e5+1;
      seg.resize(4*maxi,0);
      long long cost=0;
      for(int i=0;i<nums.size();i++)
      {
        int x=nums[i];
        cost+=min(query(1,x-1,1,maxi,0),query(x+1,maxi,1,maxi,0));
        cost=cost%mod;
        update(1,maxi,0,x);
      }
      return cost;
        
    }
};