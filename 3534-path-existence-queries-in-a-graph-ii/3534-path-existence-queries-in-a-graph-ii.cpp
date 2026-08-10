class Solution {
public:
int func(vector<pair<int,int>>&rough,int x,int d)
{
    int l=0;
    int r=rough.size()-1;
    int ans;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if((rough[mid].first-x)<=d)
        {
             ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
}
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    vector<pair<int,int>>rough;
    for(int i=0;i<n;i++)
    {
        rough.push_back({nums[i],i});
    }
    sort(rough.begin(),rough.end());
    map<int,int>mp;
      for(int i=0;i<nums.size();i++)
        {
            mp[rough[i].second]=i;
        }
        int cols=log2(n)+1;
      vector<vector<int>>sparse(n,vector<int>(cols,INT_MAX));
      for(int i=0;i<n;i++)
      { 
            sparse[i][0]=func(rough,rough[i].first,maxDiff);
      }
    for(int j=1;j<cols;j++)
    {
        for(int i=0;i<n;i++)
        {
        if(sparse[i][j-1]!=INT_MAX)
        {
            sparse[i][j]=sparse[sparse[i][j-1]][j-1];
        }
        }
    }
    vector<int>result;
    for(auto q:queries)
    {
       int u=q[0];
       int v=q[1];
       int i=mp[u];
       int j=mp[v];
       if(i==j)
       {
        result.push_back(0);
        continue;
       }
       if(i>j)
       {
        swap(i,j);
       } 
       int jumps=0;
       for(int l=cols-1;l>=0;l--)
       {
          if(sparse[i][l]<j)
          {
             i=sparse[i][l];
             jumps+=(1<<l);//2^j;
          }
       }
       if(sparse[i][0]>=j)
       {
         jumps++;
         result.push_back(jumps);
       }
       else
       {
        result.push_back(-1);
       }
    }
    return result;
    }
};