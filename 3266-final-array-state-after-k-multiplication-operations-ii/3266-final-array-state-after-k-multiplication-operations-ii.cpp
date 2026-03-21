class Solution {
public:
    int mod = 1e9+7;

    int power(long long a, long long b, int mod) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier==1)
        {
            return nums;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i=0;i<nums.size();i++) {
            pq.push({nums[i], i});
        }

        int maxi = *max_element(nums.begin(), nums.end());

        while(k > 0 && multiplier * 1LL * pq.top().first <= maxi) {
            auto x = pq.top(); pq.pop();
            pq.push({(x.first * multiplier) % mod, x.second});
            k--;
        }

        int n = nums.size();
        int cyc = k / n;
        int rem = k % n;

        int pow = power(multiplier, cyc, mod);

        while(pq.size()) {
            auto val = pq.top().first;
            auto ind = pq.top().second;
            pq.pop();

            long long cur = (1LL * val * pow) % mod;

            if(rem > 0) {
                cur = (cur * multiplier) % mod;
                rem--;
            }

            nums[ind] = cur;
        }

        return nums;
    }
};