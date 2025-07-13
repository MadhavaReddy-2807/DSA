class NumArray {
public:
vector<int>seg;
vector<int>rough;
void build(int l,int r,int i,vector<int>&nums)
{
    if(l==r)
    {
        seg[i]=nums[l];
        return;
    }
    else
    {
        int mid=(l+r)/2;
        build(l,mid,2*i+1,nums);
        build(mid+1,r,2*i+2,nums);
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }
}
    NumArray(vector<int>& nums) {
        seg.resize(nums.size()*4,0);
        rough.assign(nums.begin(),nums.end());
        build(0,nums.size()-1,0,nums);
    }
void updateseg(int index,int val,int l,int r,int i)
{
    if(l==r)
    {
        seg[i]+=val;
        return;
    }
    else
    {
        seg[i]+=val;
        int mid=(l+r)/2;
        if(index<=mid)
        {
            updateseg(index,val,l,mid,2*i+1);
        }
        else
        {
            updateseg(index,val,mid+1,r,2*i+2);
        }
    }
}
    void update(int index, int val) {
        updateseg(index,-rough[index],0,rough.size()-1,0);
        updateseg(index,val,0,rough.size()-1,0);
    }
int sumrangeseg(int l,int r,int start,int end,int index)
{
    if(l>end||start>r)
    {
        return 0;
    }
    if(l<=start&&end<=r)
    {
        return seg[index];
    }
    int mid=(start+end)/2;
    return sumrangeseg(l,r,start,mid,2*index+1)+sumrangeseg(l,r,mid+1,end,2*index+2);
}
    int sumRange(int left, int right) {
        return sumrangeseg(left,right,0,rough.size()-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */


