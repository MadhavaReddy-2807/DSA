class Solution {
public:
int man(vector<int>&a,vector<int>&b)
{
    return abs(a[0]-b[0])+abs(a[1]-b[1]);
}
bool  func(int distance,vector<vector<int>>&points,int color,vector<int>&colors,int node)
{
    if(colors[node]!=-1)
    {
        return colors[node]==color;
    }
    colors[node]=color;
  for(int j=0;j<points.size();j++)
  {
    if(j!=node && man(points[node],points[j])<distance)// should not have minimum
    {
        if(colors[j]==-1)
        {
            if(!func(distance,points,!color,colors,j))
            {
                return false;
            }
        }
        else
        {
            if(colors[j]==color)
            {
                return false;
            }
        }
    }
  }
  return true;
}
bool check(int distance,vector<vector<int>>&points,vector<int>&colors)
{

   for(int i=0;i<points.size();i++)
   {
    if(colors[i]==-1)
    {
        if(!func(distance,points,0,colors,i))
        {
            return false;
        }
    }
   }
   return true;
}
    int maxPartitionFactor(vector<vector<int>>& points) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        if(points.size()<=2)
        {
            return 0;
        }
        for(int i=0;i<points.size();i++)
        {
            for(int j=0;j<points.size();j++)
            {
                if(i!=j)
                {
                    auto p1=points[i];
                    auto p2=points[j];
                    int dist=abs(p1[0]-p2[0])+abs(p1[1]-p2[1]);
                    maxi=max(maxi,dist);
                    mini=min(mini,dist);
                }
            }
        }
        int l=mini;
        int r=maxi;
       int res=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            vector<int>colors(points.size(),-1);
            if(check(mid,points,colors))
            {
                res=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return res;
    }
};