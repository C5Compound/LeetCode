class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> re(2, -1);
        if (nums.empty()) {
            return re; 
        }
        // 二分查找下界
        int l = 0, r = nums.size() - 1, m;
        while (l < r) {
            m = l + ((r - l) >> 1);
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (nums[l] != target) {
            return re;
        }
        re[0] = l;
        // 二分查找上界
        l = 0, r = nums.size() - 1;
        while (l < r) {
            m = l + ((r - l + 1) >> 1);
            if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m;
            }
        }
        re[1] = r;
        return re;
    }
};