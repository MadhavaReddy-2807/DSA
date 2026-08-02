class Solution {
public:
    string subStrHash(string s, int p, int m, int k, int hashValue) {
        int r=s.length()-1;
        long long  powerk_1=1;
        for(int i=0;i<k-1;i++)
        {
            powerk_1=(powerk_1*p)%m;
        }
        long long hash=0;
        int index=-1;
        for(int l=s.length()-1;l>=0;l--)
        {
            hash=(hash*p+(s[l]-'a'+1))%m;
            if((r-l+1)==k)
            {
                if(hash==hashValue)
                {
                    index=l;
                }
             hash = ((hash - (s[r]-'a'+1) * powerk_1) % m + m) % m;            
               r--;
            }
        }
        return s.substr(index,k);
    }
};