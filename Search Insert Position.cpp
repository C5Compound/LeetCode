class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 二分
        if (nums.empty()) {
            return -1;
        }
        int l = 0, r = nums.size() - 1, m;
        while (l < r) {
            m = l + ((r - l + 1) >> 1);
            if (nums[m] >= target) {
                r = m - 1;
            } else {
                l = m;
            }
        }
        return nums[l] < target ? l + 1 : 0;
    }
};