class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size()-1;
        int i=0;
        int j=n;
        while(j>0&&arr[j]>=arr[j-1])
        {
            j--;
        }
        if(j==0)
        {
            return 0;
        }
        int res=j;
        while(i<j&&(i==0||arr[i]>=arr[i-1]))
        {
            while(j<arr.size()&&(arr[i]>arr[j]))
            {
                j++;
            }
            cout<<i<<j<<endl;
            res=min(res,j-i-1);
            i++;
        }
        return res;
    }
};