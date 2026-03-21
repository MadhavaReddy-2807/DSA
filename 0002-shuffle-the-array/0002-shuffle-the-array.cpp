class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>a(nums.begin(),nums.begin()+n);
        vector<int>b(nums.begin()+n,nums.end());
        vector<int>ans;
        int j=0;
        int k=0;
        for(int i=0;i<2*n;i++)
        {
            if(i%2)
            {
                ans.push_back(b[j]);
                j++;
            }
            else
            {
                ans.push_back(a[k]);
                k++;
            }
        }
        return ans;

    }
};