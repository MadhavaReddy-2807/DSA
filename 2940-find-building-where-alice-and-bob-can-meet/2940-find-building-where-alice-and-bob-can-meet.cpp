class Solution {
public:
vector<int>seg;
void build(int index,int l,int r,vector<int>heights)
{
    if(l==r)
    {
        seg[index]=l;
        return;
    }
    int mid=(l+r)/2;
    build(2*index+1,l,mid,heights);
    build(2*index+2,mid+1,r,heights);
    int left=seg[2*index+1];
    int right=seg[2*index+2];
    if(heights[left]>=heights[right])
    {
        seg[index]=left;
    }
    else
    {
        seg[index]=right;
    }
}
int maxquery(int l,int r,int ql,int qr,int index,vector<int>&heights)
{
    if(qr<l||r<ql)
    {
        return INT_MIN;
    }
    if(ql<=l&&r<=qr)
    {
        return seg[index];
    }
    int mid=(l+r)/2;
    int left=maxquery(l,mid,ql,qr,2*index+1,heights);
    int right=maxquery(mid+1,r,ql,qr,2*index+2,heights);
    if(left==INT_MIN)
    {
        return right;
    }
    if(right==INT_MIN)
    {
        return left;
    }
    return heights[left]>=heights[right]?left:right;
}
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        seg.resize(4*n,0);
        build(0,0,heights.size()-1,heights);
        vector<int>result;
        for(int i=0;i<queries.size();i++)
        {
            int a=queries[i][0];
            int b=queries[i][1];
            if(a>b)
            {
                swap(a,b);
            }
            int l=b+1;
            int r=heights.size()-1;
            if(heights[b]>heights[a])
            {
                result.push_back(b);
                continue;
            }
            if(a==b)
            {
                result.push_back(a);
                continue;
            }
            int ans=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                int x=maxquery(0,heights.size()-1,l,mid,0,heights);
                if(x!=INT_MIN&&heights[a]<heights[x]&&heights[b]<heights[x])
                {
                    ans=x;
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