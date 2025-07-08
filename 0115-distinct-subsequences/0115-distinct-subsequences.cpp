class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int>prev(t.length()+1,0);
        vector<int>current(t.length()+1,0);
        prev[0]=1;
        for(int i=1;i<=s.length();i++)
        {
            current[0]=1;
            for(int j=1;j<=t.length();j++)
            {
                if(s[i-1]==t[j-1])
                {
                    current[j]=(long long )prev[j-1]+prev[j];
                }
                else
                {
                    current[j]=prev[j];
                }

            }
            prev=current;
        }
        return prev[t.length()];
    }
};