class Solution {
public:
int func(int cost,vector<vector<int>>&a)
{
    int n=a.size();
   for(int i=0;i<n;i++)
   {
      if(cost<a[i][1])
      {
        return 0;
      }
      cost=cost-a[i][0];
   }
   return 1;
}
    int minimumEffort(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](auto &x, auto &y){
    return (x[1] - x[0]) > (y[1] - y[0]);
});
       long long  l=0;
       long long r=1e15;
       int ans=-1;
       while(l<=r)
       {
          long  long  mid=(l+r)/2;
          if(func(mid,a))
          {
            ans=mid;
            r=mid-1;
          }
          else
          {
            l=mid+1;
          }
       }
       return ans;
    }
};