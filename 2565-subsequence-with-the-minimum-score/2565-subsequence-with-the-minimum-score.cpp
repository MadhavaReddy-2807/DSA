class Solution {
public:
    int minimumScore(string s, string t) {
          int m=s.length();
          int n=t.length();
          vector<int>pre(m,0);
          vector<int>suff(m,0);
          int j=0;
          for(int i=0;i<m&&j<n;i++)
          {
              if(s[i]==t[j])
              {
                pre[i]++;
                j++;
              }
              if(i>0)
              {
              pre[i]=pre[i]+pre[i-1];
              }
          }
           j=n-1;
            for(int i=m-1;i>=0&&j>=0;i--)
            {
                if(s[i]==t[j])
                {
                    suff[i]++;
                    j--;
                }
                if(i!=m-1)
                {
                    suff[i]=suff[i]+suff[i+1];
                }
            }
            int res=INT_MAX;
            for(int i=0;i<m-1;i++)
            {
                res=min(res,n-pre[i]-suff[i+1]);
            }
            res=min(res,n-pre[m-1]);
            res=min(res,n-suff[0]);
            return res;
    }
};