class Solution {
public:
int count(int i,int l,int r,vector<int>&walls)
{
    auto it=lower_bound(walls.begin(),walls.end(),l);
    auto it1=upper_bound(walls.begin(),walls.end(),r);
    return it1-it;
}
int func(int i,vector<pair<int,int>>&range,int dir,vector<int>&robots,vector<int>&walls)
{
    if(i==robots.size())
    {
        return 0;
    }
    int res=INT_MIN;
    if(i==0)
    {
        res=max(res,count(i,range[i].first,robots[i],walls)+func(i+1,range,0,robots,walls));
        res=max(res,count(i,robots[i],range[i].second,walls)+func(i+1,range,1,robots,walls));
    }
    else
    {
        if(dir==1)
        {
            int l=max(range[i-1].second+1,range[i].first);
            res=max(res,count(i,l,robots[i],walls)+func(i+1,range,0,robots,walls));
            res=max(res,count(i,robots[i],range[i].second,walls)+func(i+1,range,1,robots,walls));

        }
        else
        {
         res=max(res,count(i,range[i].first,robots[i],walls)+func(i+1,range,0,robots,walls));
        res=max(res,count(i,robots[i],range[i].second,walls)+func(i+1,range,1,robots,walls));
        }
    }
    return res;
}
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
      vector<pair<int,int>>r;
      r.push_back({INT_MIN,INT_MIN});
      for(int i=0;i<robots.size();i++)
      {
        r.push_back({robots[i],distance[i]});
      }
      r.push_back({INT_MAX,INT_MAX}); 
      sort(r.begin(),r.end());  
      sort(walls.begin(),walls.end());
      sort(robots.begin(),robots.end());
      vector<pair<int,int>>range;
      int n=robots.size();
      for(int i=1;i<=n;i++)
      {
        int l=max(r[i].first-r[i].second,r[i-1].first+1);
        int x=min(r[i].first+r[i].second,r[i+1].first-1);
        range.push_back({l,x});
      }
      return func(0,range,0,robots,walls);
         
    }
};