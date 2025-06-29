class Solution {
public:

unordered_map<string,vector<char>>mp;
unordered_map<string,bool>dp;
bool next(string s,string curr,int level,int index)
{
    if(level==1)
    {
        return true;
    }
    if(index==level-1)
    {
        if(dp.count(curr))
        {
            return dp[curr];
        }
        return dp[curr]=next(curr,"",level-1,0);
    }
    string join="";
    for(int i=index;i<index+2;i++)
    {
        join+=s[i];
    }

    if(mp[join].size()==0)
    {
        return false;
    }
    for(int i=0;i<mp[join].size();i++)
    {
        if(next(s,curr+mp[join][i],level,index+1))
        {
            return true;
        }
    }
    return false;

}
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(int i=0;i<allowed.size();i++)
        {
            string rough="";
            for(int j=0;j<2;j++)
            {
                rough+=allowed[i][j];
            }
            mp[rough].push_back(allowed[i][2]);
        }
        return next(bottom,"",bottom.length(),0);
    }
};