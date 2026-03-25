class Solution {
public:
int m;
int n;
    int minFlips(vector<vector<int>>& mat) {
        int mask=0;
        m=mat.size();
        n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j])
                {
                mask=mask|(1<<(i*n+j));
                }
            }
        }
        queue<pair<int,int>>q;
        vector<vector<int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
        q.push({mask,0});
        unordered_set<int>st;
        st.insert(mask);
        while(!q.empty())
        {
            int curr=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(curr==0)
            {
                return steps;
            }
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    
                    int newmask=curr;
                    newmask ^= (1<<(i*n+j));
                    for(auto dir:dirs)
                    {
                        int ni=i+dir[0];
                        int nj=j+dir[1];
                        if(ni<0||nj<0||ni>=m||nj>=n)
                        {
                            continue;
                        }
                        newmask=newmask^(1<<(ni*n+nj));
                    }
                        if(st.find(newmask)==st.end())
                        {
                            st.insert(newmask);
                            q.push({newmask,steps+1});
                        }
                }
            }
        }
        return -1;
    }
};