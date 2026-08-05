class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<vector<int>>xors(n,vector<int>(n,0)),maxi(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            xors[i][i]=nums[i];
            maxi[i][i]=nums[i];
        }
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {
                int j=i+len-1;
                xors[i][j]=xors[i+1][j]^xors[i][j-1];
                maxi[i][j]=max(xors[i][j],max(maxi[i+1][j],maxi[i][j-1]));
            }
        }
        vector<int>result;
        for(auto q:queries)
        {
            int u=q[0];
            int v=q[1];
            result.push_back(maxi[u][v]);
        }
        return result;
    }
};