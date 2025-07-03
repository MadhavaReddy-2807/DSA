class Solution {
public:
vector<int>left;
vector<int>right;
void func(vector<int>&nums)
{
    int n=nums.size();
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty()&&nums[st.top()]>=nums[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            left[i]=-1;
        }
        else 
        {
            left[i]=st.top();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        st.pop();
    }
    // st.clear();
   for(int i=n-1;i>=0;i--)
    {
        while(!st.empty()&&nums[st.top()]>nums[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            right[i]=-1;
        }
        else 
        {
            right[i]=st.top();
        }
        st.push(i);
    }
}
void func1(vector<int>&nums)
{
    int n=nums.size();
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty()&&nums[st.top()]<=nums[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            left[i]=-1;
        }
        else 
        {
            left[i]=st.top();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        st.pop();
    }
   for(int i=n-1;i>=0;i--)
    {
        while(!st.empty()&&nums[st.top()]<nums[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            right[i]=-1;
        }
        else 
        {
            right[i]=st.top();
        }
        st.push(i);
    }
}
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        left.resize(n,-1);
        right.resize(n,-1);
        func(nums);
        int mini=0;
        for(int i=0;i<n;i++)
        {
            int l,r;
            if(left[i]==-1)
            {
                l=i+1;
            }
            else
            {
                l=i-left[i];
            }
            if(right[i]==-1)
            {
                r=n-i;
            }
            else
            {
                r=right[i]-i;
            }
            // cout<<nums[i]<<r<<l;
            mini+=nums[i]*r*l;
        }
        func1(nums);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            int l,r;
            if(left[i]==-1)
            {
                l=i+1;
            }
            else
            {
                l=i-left[i];
            }
            if(right[i]==-1)
            {
                r=n-i;
            }
            else
            {
                r=right[i]-i;
            }
            // cout<<nums[i]<<r<<l;
            maxi+=nums[i]*r*l;
        }

        return maxi-mini;
       
    }
};