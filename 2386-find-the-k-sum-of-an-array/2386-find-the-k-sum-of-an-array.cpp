class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                sum+=nums[i];
            }
            nums[i]=abs(nums[i]);
        }
        if(k==1)
        {
            return sum;
        }
        k--;
        sort(nums.begin(),nums.end());
        priority_queue<pair<long long ,long long >,vector<pair<long long ,long long >>,greater<pair<long long,long long>>>pq;
        pq.push({nums[0],0});
        k--;
        while(!pq.empty()&&k!=0)
        {
            k--;
            long long  val=pq.top().first;
            cout<<val;
            int index=pq.top().second;
            pq.pop();
            if(index+1<nums.size())
            {
                pq.push({val+nums[index+1],index+1});
                pq.push({val+nums[index+1]-nums[index],index+1});
            }
        }
        return sum-pq.top().first;
    }
};