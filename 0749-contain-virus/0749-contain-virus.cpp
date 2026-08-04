class Solution {
public:
int dfs(int i,int j,int m,int n,vector<vector<int>>&grid,vector<vector<int>>&visited,unordered_set<int>
&st)
{
    if(i<0||j<0||i>=m||j>=n||visited[i][j]||grid[i][j]==-1)
    {
        return 0;
    }
    if(grid[i][j]==0)
    {
        st.insert(i*n+j);
        return 1;
    }
    int res=0;
    visited[i][j]=1;
    res+=dfs(i+1,j,m,n,grid,visited,st);
    res+=dfs(i,j+1,m,n,grid,visited,st);
    res+=dfs(i,j-1,m,n,grid,visited,st);
    res+=dfs(i-1,j,m,n,grid,visited,st);
    // visited[i][j]=0;
return res;
}
void dfs2(int i,int j,int m,int n,vector<vector<int>>&grid,vector<vector<int>>&visited)
{
    if(i<0||j<0||i>=m||j>=n||visited[i][j]||grid[i][j]==-1)
    {
        return ;
    }
    if(grid[i][j]==0)
    {
        visited[i][j]=1;
        grid[i][j]=1;
        return;
    }
    visited[i][j]=1;
    dfs2(i,j+1,m,n,grid,visited);
    dfs2(i+1,j,m,n,grid,visited);
    dfs2(i,j-1,m,n,grid,visited);
    dfs2(i-1,j,m,n,grid,visited);
    // visited[i][j]=0;

}
void update(int i,int j,int m,int n,vector<vector<int>>&grid)
{
     if(i<0||j<0||i>=m||j>=n||grid[i][j]!=1)
    {
        return ;
    }
    grid[i][j]=-1;
    update(i+1,j,m,n,grid);
    update(i,j+1,m,n,grid);
    update(i-1,j,m,n,grid);
    update(i,j-1,m,n,grid);
}
    int containVirus(vector<vector<int>>& grid) {
        // if spreading 
        int spreading=1;
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        while(spreading)
        {
           vector<vector<int>>visited(m,vector<int>(n,0));
           int size=0;
           int x,y;
           int req=0;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==1&&!visited[i][j])
                    {
                        //do dfs;
                        unordered_set<int>st;
                        int walls=dfs(i,j,m,n,grid,visited,st);
                        int  virus_size=st.size();
                        cout<<virus_size;
                        if(virus_size>=size)
                        {
                            size=virus_size;
                            req=walls;
                            x=i;
                            y=j;
                        }
                    }
                }
            }
            res+=req;
            //do -1 , for all region of x,y;
            vector<vector<int>>visited2(m,vector<int>(n,0));
            update(x,y,m,n,grid);
            spreading=0;
            // check if any 1 present;
             for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==1&&!visited2[i][j])
                    {
                        //do dfs;
                        dfs2(i,j,m,n,grid,visited2);
                        spreading=1;
                      
                    }
                }
            }
            
        }
        return res;
        
    }
};