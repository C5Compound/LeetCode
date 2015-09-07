class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> re;
        if (digits.empty()) {
            return re;
        }
        dfs(digits, 0, re, "");
        return re;
    }
    void dfs(string &digits, int n, vector<string> &strs, string str) {
        if (digits.size() == n) {
            strs.push_back(str);
            return;
        }
        static char *ss[10] = {" ", "'", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
        char *p = ss[digits[n] - '0'];
        while (*p != '\0') {
            dfs(digits, n + 1, strs, str + *p);
            ++p;
        }
    }
};