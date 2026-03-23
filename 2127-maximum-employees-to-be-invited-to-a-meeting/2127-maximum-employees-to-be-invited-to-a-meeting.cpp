class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        {
            indegree[favorite[i]]++;
        }
        queue<int>q;
        vector<int>depth(n,1);
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                depth[i]=1;
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            int next=favorite[curr];
            depth[next]=max(depth[next],depth[curr]+1);
            indegree[next]--;
            if(indegree[next]==0)
            {
                q.push(next);
            }
        }
        int x=0;
        int res=0;
        for(int i=0;i<n;i++)
        {
            int cl=0;
            int curr=i;
            while(indegree[curr]!=0)
            {
                indegree[curr]=0;
                int next=favorite[curr];
                cl++;
                curr=next;
            }
            if(cl==2)
            {
                x+=depth[i]+depth[favorite[i]];
            }
            else
            {
                res=max(res,cl);
            }
        }
        return max(res,x);
    } 
};