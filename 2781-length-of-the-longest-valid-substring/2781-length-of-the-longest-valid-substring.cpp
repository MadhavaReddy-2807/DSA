class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> st(forbidden.begin(), forbidden.end());

        int n = word.size();
        int l = 0;
        int res = 0;

        for (int r = 0; r < n; r++) {
            for (int len = 1; len <= 10 && r - len + 1 >= l; len++) {
                if (st.count(word.substr(r - len + 1, len))) {
                    l = r - len + 2;
                    break;
                }
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};