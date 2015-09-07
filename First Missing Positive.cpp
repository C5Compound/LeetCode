class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 保存大于re的最左端元素的索引
        int re = 1, expos = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (re == nums[i]) {
                ++re;
                i = expos == INT_MAX ? i : expos - 1;
            } else if (re < nums[i]) {
                expos = min(expos, i);
            }
        }
        return re;
    }
};

// 来自discuss的漂亮方法
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int k = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] <= k && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i + 1 != nums[i]) {
                return i + 1;
            }
        }
        return 1 + k;
    }
};