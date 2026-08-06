map<pair<string,string>,int>mp;
class WordFilter {
public:
vector<string>prefix(string&s)
{
    string rough="";
    vector<string>result;
    for(int i=0;i<s.length();i++)
    {
        rough=rough+s[i];
        result.push_back(rough);
    }
    return result;
}
vector<string>suffix(string &s)
{
    string rough="";
    vector<string>result;
    for(int i=s.length()-1;i>=0;i--)
    {
        rough=s[i]+rough;
        result.push_back(rough);
    }
    return result;
}
    WordFilter(vector<string>& words) {
        mp.clear();
        for(auto index=0;index<words.size();index++)
        {
            string s=words[index];
            vector<string>pre=prefix(s);
            vector<string>suf=suffix(s);
            for(int i=0;i<pre.size();i++)
            {
                for(int j=0;j<suf.size();j++)
                {
                    mp[{pre[i],suf[j]}]=index;
                }
            }
        }
    }
    
    int f(string pref, string suff) {
        if(mp.count({pref,suff}))
        {
            return mp[{pref,suff}];
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */