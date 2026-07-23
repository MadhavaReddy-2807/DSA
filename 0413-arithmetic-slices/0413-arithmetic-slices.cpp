class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int setcount=0;
        int result=0;
        if(nums.size()<=2)
        {
            return 0;
        }
        int diff;
        for(int i=1;i<nums.size();i++)
        {
            if(setcount==0)
            {
                diff=nums[i]-nums[i-1];
                setcount=2;
            }
            else
            {
                 if(nums[i]-nums[i-1]==diff)
                 {
                    setcount++;
                 }
                 else
                 {
                    diff=nums[i]-nums[i-1];
                    result+=(setcount-2)*(setcount-1)/2;
                   setcount=2;
                 }
            }
        } 
         result+=(setcount-2)*(setcount-1)/2;

        return result;
    }
};