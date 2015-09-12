int rob(vector<int>& nums) {
    int len = nums.size(), a = 0, b = 0;
    for (int i = 0; i < len; ++i) {
        if (i % 2) {
            b = max(b + nums[i], a);
        } else {
            a = max(a + nums[i], b);
        }
    }
    return max(a, b);
}


int rob(vector<int>& nums) {
    int len = nums.size();
    if (len < 2) {
        return len < 1 ? 0 : nums[0];
    }
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (i % 2) {
            b = max(b + nums[i], a);
        } else {
            a = max(a + nums[i], b);
        }
    }
    for (int i = 1; i < len; ++i) {
        if (i % 2) {
            d = max(d + nums[i], c);
        } else {
            c = max(c + nums[i], d);
        }
    }
    return max(max(a, b), max(d, c));
}