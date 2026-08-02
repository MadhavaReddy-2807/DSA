class Solution {
public:
    vector<int> ans1;
    vector<int> ans2;

    vector<int> find(string s) {
        int n = s.length();
        vector<int> ans(n, 1);
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) dp[i][i] = true;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (len == 2) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }
                if (dp[i][j]) {
                    ans[i] = max(ans[i], len);
                }
            }
        }
        return ans;
    }

    int dp[1001][1001][2];

    int func(string &s, string &t, int i, int j, int flag) {
        if (i >= s.length() || j < 0) {
            if (i < s.length()) return ans1[i];
            if (j >= 0) return ans2[j];
            return 0;
        }
        if (dp[i][j][flag] != -1) {
            return dp[i][j][flag];
        }
        int ans = INT_MIN;
        if (flag) {
            if (s[i] == t[j]) {
                ans = 2 + func(s, t, i + 1, j - 1, 1);
            } else {
                ans = max(ans1[i], ans2[j]);
            }
        } else {
            if (s[i] == t[j]) {
                ans = max(ans, 2 + func(s, t, i + 1, j - 1, 1));
            }
            ans = max(ans, func(s, t, i + 1, j, flag));
            ans = max(ans, func(s, t, i, j - 1, flag));
        }
        return dp[i][j][flag] = ans;
    }

    int longestPalindrome(string s, string t) {
        memset(dp, -1, sizeof(dp));
        ans1 = find(s);

        reverse(t.begin(), t.end());
        ans2 = find(t);
        reverse(ans2.begin(), ans2.end());
        reverse(t.begin(), t.end());

        int maxi = *max_element(ans2.begin(), ans2.end());
        maxi = max(maxi, *max_element(ans1.begin(), ans1.end()));
        maxi = max(maxi, func(s, t, 0, t.length() - 1, 0));
        return maxi;
    }
};