vector<long long>fact;
vector<long long>invfact;
long long done=false;
long long mod=1e9+7;
long long power(long long a,long long b,long long mod)
{
    long long res=1;
    while(b)
    {
        if(b&1)
        {
            res=(1LL*res*a)%mod;
        }
        a=(1LL*a*a)%mod;
        b=b/2;
    }
    return res;
}
void precompute()
{
    done=true;
    fact.resize(1e5+1,0);
    invfact.resize(1e5+1,0);
    fact[0]=1;
    invfact[0]=1;
    for(long long i=1;i<=1e5;i++)
    {
        fact[i]=(1LL*fact[i-1]*i)%mod;
    }
    invfact[1e5]=power(fact[1e5],mod-2,mod);
    for(long long i=1e5-1;i>=0;i--)
    {
        invfact[i]=(1LL*invfact[i+1]*(i+1))%mod;
    }
}
long long c(long long a,long long b)
{
    return ((fact[a]*invfact[b])%mod*invfact[a-b])%mod;
}
long long func(long long m,long long n)
{
    const long long inv6 = power(6, mod-2, mod);
long long A = (m * m % mod) * n % mod;
long long B = (1LL * n * n % mod - 1 + mod) % mod;

return (A * B % mod) * inv6 % mod;}
class Solution {
public:
    int distanceSum(int m, int n, int k) {
        if(!done)
        {
            precompute();
        }
        return (c(1LL*n*m-2,k-2)%mod*((func(m,n)+func(n,m)%mod))%mod)%mod;
    }
};