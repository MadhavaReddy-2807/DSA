class Solution {
public:

    bool func(int k, vector<int>& workers, vector<int>& tasks,
              int pills, int s)
    {
        multiset<int> t;
        for(int i = 0; i < k; i++)
        {
            t.insert(tasks[i]);
        }

        int p = pills;
        for(int i = workers.size() - k; i < workers.size(); i++)
        {
            int w = workers[i];
            auto it = t.upper_bound(w);

            if(it != t.begin())
            {
                --it;
                t.erase(it);
            }
            else
            {
                // Cannot do any task without a pill
                if(p == 0)
                    return false;

                // With pill, worker can handle up to w + s
                it = t.upper_bound(w + s);

                if(it == t.begin())
                    return false;

                --it;
                t.erase(it);
                p--;
            }
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers,
                      int pills, int strength)
    {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int l = 0;
        int r = min(tasks.size(), workers.size());
        int ans = 0;

        while(l <= r)
        {
            int mid = (l + r) / 2;

            if(func(mid, workers, tasks, pills, strength))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return ans;
    }
};