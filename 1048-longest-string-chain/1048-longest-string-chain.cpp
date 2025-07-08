class Solution {
public:
int func(string a,string b)
{
    if(a.length()>=b.length())
    {
        return false;
    }
    int i=0;
    int j=0;
    int count=0;
    while(i<a.length()&&j<b.length())
    {
        if(a[i]==b[j])
        {
            i++;
            j++;
        }
        else
        {
            count++;
            j++;
        }
    }
    count+=b.length()-j;
    return count==1;
}
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<vector<int>>dp1(words.size()+1,vector<int>(words.size()+1,0));
        sort(words.begin(),words.end(),[](string a,string b){
            return a.length()<b.length();
        });
        vector<int>size(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(func(words[j],words[i]))
                {
                    if(size[i]<1+size[j])
                    {
                        size[i]=1+size[j];
                    }
                }
            }
        }
        int maxi=*max_element(size.begin(),size.end());
        return maxi;
    }
};