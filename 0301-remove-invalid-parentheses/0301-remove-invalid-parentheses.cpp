class Solution {
public:
    vector<string> result;
    unordered_set<string> seen;
    unordered_set<string> visited;
    int maxLen = 0;

    void func(const string& s, int i, string& curr, int open, int close) {
        if (i == s.length()) {
            if (open == close) {
                if (curr.length() > maxLen) {
                    result.clear();
                    result.push_back(curr);
                    seen.clear();
                    seen.insert(curr);
                    maxLen = curr.length();
                } else if (curr.length() == maxLen && seen.find(curr) == seen.end()) {
                    result.push_back(curr);
                    seen.insert(curr);
                }
            }
            return;
        }

        string key = to_string(i) + "_" + to_string(open) + "_" + to_string(close) + "_" + curr;
        if (visited.count(key)) return;
        visited.insert(key);

        char c = s[i];

        // Exclude current character if it's a parenthesis
        if (c == '(' || c == ')') {
            func(s, i + 1, curr, open, close);
        }

        // Include current character
        curr.push_back(c);
        if (c != '(' && c != ')') {
            func(s, i + 1, curr, open, close);
        } else if (c == '(') {
            func(s, i + 1, curr, open + 1, close);
        } else if (c == ')' && open > close) {
            func(s, i + 1, curr, open, close + 1);
        }
        curr.pop_back();  // backtrack
    }

    vector<string> removeInvalidParentheses(string s) {
        result.clear();
        seen.clear();
        visited.clear();
        maxLen = 0;
        string curr = "";
        func(s, 0, curr, 0, 0);
        return result;
    }
};
