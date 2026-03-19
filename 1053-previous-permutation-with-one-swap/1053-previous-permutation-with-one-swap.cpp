class Solution {
public:
    int find(set<int>&st,int val)
    {
        if(st.size()==0)
        {
            return -1;
        }
        auto it=st.lower_bound(val);
        if(it!=st.begin())
        {
            it--;
            return *it;
        }
        else
        {
            return -1;
        }
    }
    vector<int> prevPermOpt1(vector<int>& arr) {
        set<int>st;
        int n=arr.size();
        vector<int>rough(n,-1);
        map<int,int>mp;
        int val;
        int idx=-1;
        for(int i=n-1;i>=0;i--)
            {
                rough[i]=find(st,arr[i]);
                st.insert(arr[i]);
               if(rough[i]!=-1)
               {
                   idx=i;
                   val=rough[i];
                   break;
               }
            }
        if(idx==-1)
        {
            return arr;
        }
        int j;
        for(int i=idx+1;i<n;i++)
            {
                if(arr[i]==val)
                {
                    j=i;
                    break;
                }
            }
            swap(arr[j],arr[idx]);
        return arr;
    }
};