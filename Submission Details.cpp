class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> re;
        if (nums.size() < 3) {
            return re;
        }
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 2; ++i) {
            int j = i + 1, k = len - 1, sum;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    ++j;
                    while (j < k && nums[j - 1] == nums[j]) ++j;
                } else {
                    if (sum == 0) {
                        vector<int> v(3);
                        v[0] = nums[i];
                        v[1] = nums[j];
                        v[2] = nums[k];
                        re.push_back(v);
                    }
                    --k;
                    while (k > j && nums[k + 1] == nums[k]) --k;
                }
            }
            while (i < len - 2 && nums[i + 1] == nums[i]) ++i;
        }
        return re;
    }
};