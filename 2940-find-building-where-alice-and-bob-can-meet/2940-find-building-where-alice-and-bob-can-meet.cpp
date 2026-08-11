class node{
    public:
    int val;
    node*left;
    node*right;
};
class st{
    public:
    node*root;
    st()
    {
        root=new node();
    }
    void build(node*root,int l,int r,vector<int>&nums)
    {
        if(l==r)
        {
            root->val=nums[l];
            return;
        }
        root->left=new node();
        root->right=new node();
        int mid=(l+r)/2;
        build(root->left,l,mid,nums);
        build(root->right,mid+1,r,nums);
        root->val=max(root->left->val,root->right->val);
    }
    int query(node*root,int nl,int nr,int l,int r)
    {
        if(l>nr||r<nl)
        {
            return INT_MIN;
        }
        if(l<=nl&&nr<=r)
        {
            return root->val;
        }
        int mid=(nl+nr)/2;
        int left=query(root->left,nl,mid,l,r);
        int right=query(root->right,mid+1,nr,l,r);
        return max(left,right);
    }
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>result;
        st *s=new st();
        s->build(s->root,0,nums.size()-1,nums);
        for(auto q:queries)
        {
            int a=q[0];
            int b=q[1];
            if(a==b)
            {
                result.push_back(a);
                continue;
            }
            if(a>b)
            {
                swap(a,b);
            }
            if(nums[b]>nums[a])
            {
                result.push_back(b);
                continue;
            }
            int l=b+1;
            int r=nums.size()-1;
            int ans=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                int maxi=s->query(s->root,0,nums.size()-1,b+1,mid);
                if(maxi>nums[a]&&maxi>nums[b])
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