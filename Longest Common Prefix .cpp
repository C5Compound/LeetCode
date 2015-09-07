class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string re;
        if (strs.empty()) {
            return re;
        }
        int minlen = INT_MAX;
        for (int i = 0; i < strs.size(); ++i) {
            if (strs[i].size() < minlen) {
                minlen = strs[i].size();    
            }
        }
        int maxlen = 0;
        for (int i = 0; i < minlen; ++i) {
            bool eq = true;
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != c) {
                    return re;
                } 
            }
            re.push_back(c);
        }
        return re;
    }
};