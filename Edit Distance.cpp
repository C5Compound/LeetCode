/**
 * 最短编辑距离，dp[i][j] = min(dp[i - 1][j - 1] + if(word1[i] == word2[j]) 替换
 *                             dp[i - 1][j] + 1                            删除
 *                             dp[i][j - 1] + 1)                           添加
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) {
            return word2.size();
        }
        if (word2.empty()) {
            return word1.size();
        }
        // 动态规划
        int l1 = word1.size(), l2 = word2.size(), dp[l1 + 1][l2 + 1];
        for (int i = 0; i <= l1; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= l2; ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                int cost = word1[i - 1] == word2[j - 1] ? 0 : 1;
                dp[i][j]= min(dp[i - 1][j - 1] + cost, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
            }
        }
        return dp[l1][l2];
    }
};