class Solution {
public:
    int dp[17][17];
    int memo[17][2][1 << 17];

    vector<vector<int>> dirs = {
        {2,1},{2,-1},{1,2},{1,-2},
        {-2,1},{-2,-1},{-1,2},{-1,-2}
    };

    void bfs(int index, vector<vector<int>>& pos, unordered_map<int,int>& mp)
    {
        bool vis[50][50] = {};

        int sx = pos[index][0];
        int sy = pos[index][1];

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{sx,sy}});
        vis[sx][sy] = true;
        dp[index][index] = 0;

        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();

            int d = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;

            int key = x * 50 + y;
            if(mp.count(key))
                dp[index][mp[key]] = d;

            for(auto &dir : dirs)
            {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx < 0 || ny < 0 || nx >= 50 || ny >= 50 || vis[nx][ny])
                    continue;

                vis[nx][ny] = true;
                q.push({d + 1,{nx,ny}});
            }
        }
    }

    void precompute(vector<vector<int>>& pos)
    {
        memset(dp,-1,sizeof(dp));

        unordered_map<int,int> mp;
        for(int i=0;i<pos.size();i++)
            mp[pos[i][0]*50 + pos[i][1]] = i;

        for(int i=0;i<pos.size();i++)
            bfs(i,pos,mp);
    }

    int func(int index, vector<vector<int>>& pos, int turn, int mask)
    {
        if(mask == (1<<pos.size())-1)
            return 0;

        if(memo[index][turn][mask] != -1)
            return memo[index][turn][mask];

        if(!turn)
        {
            int res = INT_MIN;
            for(int i=0;i<pos.size();i++)
            {
                if(mask&(1<<i)) continue;

                int newMask = mask | (1<<i);
                res = max(res,
                          dp[index][i] +
                          func(i,pos,1,newMask));
            }
            return memo[index][turn][mask] = res;
        }
        else
        {
            int res = INT_MAX;
            for(int i=0;i<pos.size();i++)
            {
                if(mask&(1<<i)) continue;

                int newMask = mask | (1<<i);
                res = min(res,
                          dp[index][i] +
                          func(i,pos,0,newMask));
            }
            return memo[index][turn][mask] = res;
        }
    }

    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        positions.insert(positions.begin(), {kx, ky});

        memset(memo,-1,sizeof(memo));
        precompute(positions);

        return func(0, positions, 0, 1);
    }
};