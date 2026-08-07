class Solution {
public:
vector<int>func(string &s)
{
    int i=0;
    int j=1;
    vector<int>lps(s.length(),0);
    while(j<s.length())
    {
        if(s[i]==s[j])
        {
            lps[j]=i+1;
            i++;
            j++;
        }
        else
        {
            if(i==0)
            {
                lps[j]=i;
                j++;
            }
            else
            {
                i=lps[i-1];
            }
        }
    }
    return lps;
}
int mod=1e9+7;
int dp[2][2][502][51];
long long func(string&s1,string&s2,int ltight,int rtight,int index,vector<int>&lps,int evil_index,string&evil)
{
    if(evil_index==evil.length())
    {
        return 0;
    }
    if(index==s1.size())
    {
        return 1;
    }
    if(dp[ltight][rtight][index][evil_index]!=-1)
    {
        return dp[ltight][rtight][index][evil_index];
    }
    char start=ltight?s1[index]:'a';
    char end=rtight?s2[index]:'z';
    long long ans=0;
    for(char c=start;c<=end;c++)
    {
        int nltight=ltight&&(c==start);
        int nrtight=rtight&&(c==end);
        if(evil[evil_index]==c)
        {
            ans+=func(s1,s2,nltight,nrtight,index+1,lps,evil_index+1,evil);
            ans=ans%mod;
        }
        else
        {
                int k=evil_index;
                // check any where if it is matcing else start from i=0;itself
                while(k>0&&evil[k]!=c)
                {
                    k=lps[k-1];
                }
                if(evil[k]==c)k++;
            ans+=func(s1,s2,nltight,nrtight,index+1,lps,k,evil);            
            ans=ans%mod;
        }
    }
    return dp[ltight][rtight][index][evil_index]=ans;
}
    int findGoodStrings(int n, string s1, string s2, string evil) {
        //compute lps of evil
        memset(dp,-1,sizeof(dp));
        vector<int>lps=func(evil);
        return func(s1,s2,1,1,0,lps,0,evil);
    }
};