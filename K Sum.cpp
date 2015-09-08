/**
 *  4sum
 */
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> re;
    if (nums.size() < 4) {
        return re;
    }
    sort(nums.begin(), nums.end());
    int len = nums.size();
    for (int i = 0; i < len - 3; ++i) {
        for (int j = i + 1; j < len - 2; ++j) {
            int k = j + 1, l = len - 1, sum;
            while (k < l) {
                sum = nums[i] + nums[j] + nums[k] + nums[l];
                if (sum < target) {
                    ++k;
                    while (k < l && nums[k] == nums[k - 1]) ++k;
                } else {
                    if (sum == target) {
                        vector<int> quad(4);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[k];
                        quad[3] = nums[l];
                        re.push_back(quad);
                    }
                    --l;
                    while (l > k && nums[l] == nums[l + 1]) --l;
                }
            }
            while (j < len - 2 && nums[j + 1] == nums[j]) ++j;
        }
        while (i < len - 3 && nums[i + 1] == nums[i]) ++i;
    }
    return re;
}

/**
 *  3sum closet
 */
int threeSumClosest(vector<int>& nums, int target) {
    long long re = INT_MAX;
    sort(nums.begin(), nums.end());
    int len = nums.size();
    for (int i = 0; i < len - 2; ++i) {
        int j = i + 1, k = len - 1, sum;
        while (j < k) {
            sum = nums[i] + nums[j] + nums[k];
            if (abs(sum - target) < abs(re - target)) {
                re = sum;
            }
            if (sum > target) {
                --k;
            } else {
                ++j;
            }
        }
    }
    return re;
}

/**
 *  3sum
 */
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