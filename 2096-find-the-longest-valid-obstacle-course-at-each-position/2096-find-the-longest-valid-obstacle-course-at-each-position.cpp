class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis;
         vector<int>result(n);
         for(int i=0;i<nums.size();i++)
         {
            if(lis.size()==0||lis.back()<=nums[i])
            {
               lis.push_back(nums[i]);
               result[i]=lis.size();
            }
            else
            {
              auto index=upper_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
              lis[index]=nums[i];
              result[i]=index+1; 
            }
         }
         return result;
    }
};