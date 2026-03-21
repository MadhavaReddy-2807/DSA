class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
    map<int,string>mp;
        mp[0]="Push";
        mp[1]="Pop";
        vector<string>res;
        int j=1;
        for(int i=0;i<target.size();i++,j++)
            {
                if(j!=target[i])
                {
                    res.push_back(mp[0]);
                    res.push_back(mp[1]);
                    i--;
                }
                else
                {
                    res.push_back(mp[0]);
                }
                
            }
        return res;
    }
};