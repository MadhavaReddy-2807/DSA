class Solution {
public:
class states{
    public:
    vector<int>if_parent_buy;
    vector<int>if_parent_doesnt_buy;
};
states func(vector<vector<int>>&adj,vector<int>&present,vector<int>&future,int b,int node)
{
    vector<vector<int>>ifnotu;
    vector<vector<int>>ifu;
    for(auto a:adj[node])
    {
        states s=func(adj,present,future,b,a);
        ifnotu.push_back(s.if_parent_doesnt_buy);
        ifu.push_back(s.if_parent_buy);
    }
    states s;
    for(int p=0;p<=1;p++)
    {
        int cost=(p==0?present[node]:present[node]/2);
        int profit=future[node]-cost;
        //if u not buy
        vector<int>best(b+1,0);
        vector<int>ifubought(b+1,0);
        vector<int>ifunotbought(b+1,0);
        for(int i=0;i<ifnotu.size();i++)
        {
            vector<int>temp(b+1,INT_MIN);
            for(int used=0;used<=b;used++)
            {
                for(int take=0;used+take<=b;take++)
                {
                    temp[used+take]=max(temp[used+take],ifunotbought[used]+ifnotu[i][take]);
                }
            }
            ifunotbought=temp;
        }
        best=ifunotbought;
        // if u buys;
        for(int i=0;i<ifu.size();i++)
        {
            vector<int>temp(b+1,INT_MIN);
            for(int used=0; used<=b;used++)
            {
                for(int take=0;used+take<=b;take++)
                {
                    temp[used+take]=max(temp[used+take],ifubought[used]+ifu[i][take]);
                }
            }
            ifubought=temp;
        }
        for(int i=0;i<=b;i++)
        {
            if(cost<=i)
            {
                best[i]=max(best[i],profit+ifubought[i-cost]);
            }
        }
        if(p==0)
        {
            s.if_parent_doesnt_buy=best;
        }
        else
        {
            s.if_parent_buy=best;
        }
    }
    return s;

}
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& edges, int budget) {
        vector<vector<int>>adj(n);
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            u--;
            v--;
            adj[u].push_back(v);
        }
        states s=func(adj,present,future,budget,0);
       return s.if_parent_doesnt_buy[budget];
    }
};