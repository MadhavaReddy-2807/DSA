class Solution {
public:
int func(int len,string &s,int maxi)
{
    int n=s.length();
      if(len==1)
      {
         char c='0';
         int need=0;
         for(int i=0;i<n;i++)
         {
            if(s[i]!=c)
            {
                need++;
            }
            if(i%2==0)
            {
                c=c+1;
            }
            else
            {
                c=c-1;
            }
         }
         if(need<=maxi)
         {
            return 1;
         }
         need=0;
          c='1';
         for(int i=0;i<n;i++)
         {
            if(s[i]!=c)
            {
                need++;
            }
            if(i%2==0)
            {
                c=c-1;
            }
            else
            {
                c=c+1;
            }
         }
         if(need<=maxi)
         {
            return 1;
         }
         return 0;
      }
        int i=0;
        int need=0;
         while(i<n)
         {
            int count=0;
            int curr=s[i];
            while(i<n&&s[i]==curr)
            {
                count++;
                i++;
            }
            // if there is any substring with more than req we will be break them by flipping things in b/w 
            need+=(count/(len+1));
          }
          return need<=maxi;
}
    int minLength(string s, int numOps) {
        int l=1;
        int r=s.length();
        int ans=1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(func(mid,s,numOps))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};