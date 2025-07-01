class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot=0;
        int sur=0;
        int s=0;
        for(int i=0;i<gas.size();i++)
        {
            tot+=gas[i]-cost[i];
            sur+=gas[i]-cost[i];
            if(sur<0)
            {
                s=i+1;
                sur=0;
            }
        }
        return tot<0?-1:s;
    }
};