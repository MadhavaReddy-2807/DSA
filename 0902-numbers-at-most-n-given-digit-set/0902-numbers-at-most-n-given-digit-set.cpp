class Solution {
public:
vector<int>list;
int dp[20][2][2];
int func(string s,int index,int tight,int prev)
{
    if(index>=s.length())
    {
        return prev!=-1;
    }
    if(dp[index][tight][prev+1]!=-1)
    {
        return dp[index][tight][prev+1];
    }
    int ways=0;
    int limit=tight?(s[index]-'0'):9;
    for(int i=0;i<list.size();i++)
    {
        if(list[i]<=limit)
        {
            int newtight=(tight==1)&&(list[i]==limit);
            if(list[i]==0)
            {
                ways+=func(s,index+1,newtight,prev);
            }
            else
            {
                ways+=func(s,index+1,newtight,0);
            }
        }
    }
    return dp[index][tight][prev+1]=ways;
}
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        for(auto d:digits)
        {
            list.push_back(stoi(d));
        }   
        string x=to_string(n);
        int count=0;
        vector<string>limit={"9","99","999","9999","99999","999999","9999999","99999999","999999999","9999999999"};
        for(int i=1;i<x.length();i++)
        {
            memset(dp,-1,sizeof(dp));
            count+=func(limit[i-1],0,1,-1);
        }
            memset(dp,-1,sizeof(dp));
        count+=func(x,0,1,-1);
        return count;
    }
};