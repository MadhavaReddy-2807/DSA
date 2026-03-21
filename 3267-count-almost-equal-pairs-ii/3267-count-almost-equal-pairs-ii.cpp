class Solution {
public:
unordered_set<int> func(int x)
{
    unordered_set<int>valid;
    string s=to_string(x);
    valid.insert(x);
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(s[i],s[j]);
            valid.insert(stoi(s));
            for(int i1=0;i1<n;i1++)
            {
                for(int j1=i1+1;j1<n;j1++)
                {
                    if(i1==i&&j1==j)
                    {
                        continue;
                    }
                    swap(s[i1],s[j1]);
                    valid.insert(stoi(s));
                    swap(s[i1],s[j1]);
                }
            }
            swap(s[i],s[j]);
        }
    }
    return valid;
}
    int countPairs(vector<int>& nums) {
        map<int,int>mp;
       sort(nums.begin(),nums.end());
        mp[nums[0]]++;
        int n=nums.size();
        int maxi=INT_MIN;
        int count=0;
        for(int i=1;i<n;i++)
        {
            unordered_set<int>a=func(nums[i]);
            for(auto it:a)
            {
                count+=mp[it];
            }
            mp[nums[i]]++;
        }
        return count;
    }
};