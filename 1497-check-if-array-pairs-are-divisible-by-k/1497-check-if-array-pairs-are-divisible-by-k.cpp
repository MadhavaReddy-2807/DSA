class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
      map<int,int>mp;
      for(int i=0;i<arr.size();i++)
      {
        mp[(((arr[i]+k)%k)+k)%k]++;
      }
      if(k%2==0)
        {
            if(mp[k/2]%2)
            {
                return false;
            }
        }
      for(int i=0;i<k;i++)
      {
         if(i==0)
         {
            if(mp[i]%2)
            {
                return false;
            }
         }
         else
         {
            int comp=((k-i)%k+k)%k;
            if(mp[comp]!=mp[i])
            {
                return false;
            }
         }

      }
      return true;
    }
};