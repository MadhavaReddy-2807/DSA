class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<unordered_map<int,int>> mp(k);
        vector<int> times(k);

        for(int i = 0; i < k; i++)
        {
            int index = i;
            mp[i][nums[index]]++;
            int timer = 1;

            while(index + k < nums.size())
            {
                index += k;
                timer++;
                mp[i][nums[index]]++;
            }

            times[i] = timer;
        }

        for(int i = 0; i < k; i++)
        {
            for(auto it : mp[i])
            {
                int number = it.first;
                int freq = it.second;
                mp[i][number] = times[i] - freq;
            }
        }

        vector<vector<int>> dp(k, vector<int>(1024, INT_MAX));

        // Last group
        for(int num = 0; num < 1024; num++)
        {
            if(mp[k-1].find(num) == mp[k-1].end())
            {
                dp[k-1][num] = times[k-1];
            }
        }

        for(auto it : mp[k-1])
        {
            int num = it.first;
            int freq = it.second;
            dp[k-1][num] = freq;
        }

        for(int i = k - 2; i >= 0; i--)
        {
            // Minimum cost in the next row
            int mn = INT_MAX;

            for(int x = 0; x < 1024; x++)
            {
                mn = min(mn, dp[i+1][x]);
            }

            for(int j = 0; j < 1024; j++)
            {
                // Choose a number which doesn't exist in this group.
                // All elements of this group must be changed.
                dp[i][j] = times[i] + mn;

                // Choose a number which exists in this group.
                for(auto it : mp[i])
                {
                    int number = it.first;
                    int freq = it.second;

                    if(dp[i+1][j ^ number] != INT_MAX)
                    {
                        dp[i][j] = min(
                            dp[i][j],
                            freq + dp[i+1][j ^ number]
                        );
                    }
                }
            }
        }

        return dp[0][0];
    }
};