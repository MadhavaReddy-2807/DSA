class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& a) {
        priority_queue<pair<int,int>>pq;
        map<int,int>mp;
        for(auto n:a)
            {
                mp[n]++;
            }
        for(auto it:mp)
            {
                pq.push({it.second,it.first});
            }
        vector<int>res;
        while(pq.size()>=2)
            {
                auto x=pq.top();
                pq.pop();
                auto y=pq.top();
                pq.pop();
                res.push_back(x.second);
                res.push_back(y.second);
                x.first=x.first-1;
                y.first=y.first-1;
                if(x.first)
                {
                    pq.push(x);
                }
                if(y.first)
                {
                    pq.push(y);
                }
            }
        if(pq.size())
        {
            res.push_back(pq.top().second);
        }
        return res;
        
    }
};