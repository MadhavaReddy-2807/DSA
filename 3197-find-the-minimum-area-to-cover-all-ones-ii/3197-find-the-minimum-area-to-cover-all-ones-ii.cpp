class Solution {
public:
long long res;
long long area(long long r1,long long r2,long long c1,long long c2,vector<vector<int>>&grid)
{
    long long minrow=LLONG_MAX;
    long long mincol=LLONG_MAX;
    long long maxrow=LLONG_MIN;
    long long maxcol=LLONG_MIN;
   for(long long i=r1;i<r2;i++)
   {
    for(long long j=c1;j<c2;j++)
    {
        if(grid[i][j])
        {
         minrow=min(minrow,i);
         maxrow=max(maxrow,i);
         mincol=min(mincol,j);
         maxcol=max(maxcol,j);
        }
    }
   }
   if(maxrow!=LLONG_MIN)
   {
   return (maxrow-minrow+1)*(maxcol-mincol+1);
   }
   return -1;
}
long long func(vector<vector<int>>&grid)
{
    long long m=grid.size();
    long long n=grid[0].size();
    for(long long row=1;row<m;row++)
    {
        for(long long col=1;col<n;col++)
        {
            long long top=area(0,row,0,n,grid);
            long long bl=area(row,m,0,col,grid);
            long long br=area(row,m,col,n,grid);
            if(top!=-1&&bl!=-1&&br!=-1)
            {
            res=min(res,top+bl+br);
            }
        }
    }
    for(long long col=1;col<n;col++)
    {
        for(long long row=1;row<m;row++)
        {
            long long tl=area(0,row,0,col,grid);
            long long tr=area(0,row,col,n,grid);
            long long b=area(row,m,0,n,grid);
            if(tl!=-1&&tr!=-1&&b!=-1)
            {
            res=min(res,tl+tr+b);
            }
        }
    }
    for(long long r1=1;r1<m;r1++)
    {
        for(long long r2=r1+1;r2<m;r2++)
        {
            long long t1=area(0,r1,0,n,grid);
            long long t2=area(r1,r2,0,n,grid);
            long long t3=area(r2,m,0,n,grid);
            if(t1!=-1&&t2!=-1&&t3!=-1)
            {
            res=min(res,t1+t2+t3);
            }
        }
    }
    return res;
    
}
vector<vector<int>> rotate(vector<vector<int>>&grid)
{
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>rough(n,vector<int>(m));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            rough[j][m-i-1]=grid[i][j];
        }
    }
    return rough;
}
    int minimumSum(vector<vector<int>>& grid) {
        res=LLONG_MAX;
        func(grid);
        grid=rotate(grid);
        func(grid);
        return res;
    }
};