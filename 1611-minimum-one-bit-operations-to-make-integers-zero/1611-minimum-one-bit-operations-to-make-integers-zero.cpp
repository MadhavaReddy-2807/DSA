class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<int>f(32,0);
        for(int i=1;i<=31;i++)
        {
            f[i]=2*f[i-1]+1;
            // cout<<i<<" "<<f[i];
        }
        // cout<<endl;
        int res=0;
        int op=0;
        for(int i=30;i>=0;i--)
        {
            if(n&(1<<i))
            {
                if(op==0)
                {
                    res+=f[i+1];
                }
                else
                {
                    res-=f[i+1];
                }
                // cout<<f[i];
                op=!op;
            }
        }
        return res;
    }
};