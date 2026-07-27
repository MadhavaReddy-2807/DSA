class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& arr) {
        if(arr.size()==0)
        {
            return n-1;
        }
        arr.insert(arr.begin(),{1,0});
        sort(arr.begin(),arr.end());
        if(arr[arr.size()-1][0]!=n)
        {
        arr.insert(arr.end(),{n,n-1});
        }
        int result=INT_MIN;
        for(int i=1;i<arr.size();i++)
        {
           arr[i][1]=min(arr[i][1],arr[i][0]-arr[i-1][0]+arr[i-1][1]);
        }
        for(int i=arr.size()-2;i>=0;i--)
        {
            arr[i][1]=min(arr[i][1],arr[i+1][0]-arr[i][0]+arr[i+1][1]);
           result=max(result,arr[i][1]);
        }
      for (int i = 1; i < arr.size(); i++)
{
    int d = arr[i][0] - arr[i-1][0];
    int h1 = arr[i-1][1];
    int h2 = arr[i][1];

    int peak = max(h1, h2) + (d - abs(h1 - h2)) / 2;

    result = max(result, peak);
}
        return result;

    }
};