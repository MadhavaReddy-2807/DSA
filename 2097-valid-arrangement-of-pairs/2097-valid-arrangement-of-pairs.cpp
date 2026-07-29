class Solution {
public:
vector<vector<int>>result;
void dfs(int node,map<int,stack<int>>&mp)
{
    while(!mp[node].empty())
    {
        int ne=mp[node].top();
        mp[node].pop();
        dfs(ne,mp);
        result.push_back({node,ne});
    }
}
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        map<int,stack<int>>mp;
        map<int,int>in;
        map<int,int>out;
        set<int>nodes;
        for(auto e:pairs)
        {
            int u=e[0];
            int v=e[1];
            mp[u].push(v);
            out[u]++;
            in[v]++;
            nodes.insert(u);
            nodes.insert(v);
        }
        int start=pairs[0][0];
        for(auto x:nodes)
        {
            if(out[x]-in[x]==1)
            {
                start=x;
                break;
            }
        }
        dfs(start,mp);
        reverse(result.begin(),result.end());
        return result;
    }
};