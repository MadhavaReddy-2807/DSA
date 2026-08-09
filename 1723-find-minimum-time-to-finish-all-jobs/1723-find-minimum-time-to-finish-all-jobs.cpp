class Solution {
public:
int func(int maxi,vector<int>&workers,int index,vector<int>&jobs)
{
   if(index==jobs.size())
   {
    return true;
   }
   for(int i=0;i<workers.size();i++)
   {
     if(i!=0&&workers[i]==workers[i-1])
     {
        continue;
     }
        if(workers[i]+jobs[index]<=maxi)
        {
        workers[i]+=jobs[index];
            if(func(maxi,workers,index+1,jobs))
            {
                return true;
            }
            workers[i]-=jobs[index];
        }
   }
   return false;
}
    int minimumTimeRequired(vector<int>& jobs, int k) {
       long long left=1;
       long long right=accumulate(jobs.begin(),jobs.end(),0LL);
       int ans;
       while(left<=right)
       {
        int mid=(left+right)/2;
        vector<int>rough(k,0);
        if(func(mid,rough,0,jobs))
        {
            ans=mid;
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
       }
       return ans;
    }
};