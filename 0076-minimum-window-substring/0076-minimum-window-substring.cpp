class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>have;
        map<char,int>req;
        for(int i=0;i<t.length();i++)
        {
            req[t[i]]++;
        }
        int x=0;
       int j=0;
       int i=0;
       int start=-1;
       int len=INT_MAX;
       while(j<s.length())
       {
        have[s[j]]++;
        if(req.find(s[j])!=req.end()&&(have[s[j]]==req[s[j]]))
        {
            x++;
        }
        while(x==req.size())
        {
            if((j-i+1)<len)
            {
                len=j-i+1;
                start=i;
            }   
            have[s[i]]--;
            if(have[s[i]]<req[s[i]])
            {
                x--;
            }
            i++;
        }
        j++;
       }
       if(start==-1)
       {
        return "";
       }
       return s.substr(start,len);
    }
};