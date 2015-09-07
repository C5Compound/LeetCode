class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end(), less<int>());
        vector<vector<int>> re;
        int len = nums.size();
        // 用二进制位指示是否输出该数字
        for (int i = 0; i < (1 << len); ++i) {
            vector<int> v;
            for (int j = 0; j < len; ++j) {
                if ((i & (1 << j)) > 0) {
                    v.push_back(nums[j]);
                }
            }
            re.push_back(v);
        }
        return re;
    }
};