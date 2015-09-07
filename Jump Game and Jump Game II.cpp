// 来自discuss区的不超时BFS
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)  {
            return 0;
        }
        int len = nums.size(), jumps = 0;
        int currentfloor = 0, nextfloor = 0;
        for(int i = 0; i <= currentfloor; ++i) {
            nextfloor = max(nextfloor, i + nums[i]);
            if(nextfloor >= len - 1) {
                return jumps + 1;
            }
            if(i == currentfloor) {
                currentfloor = nextfloor;
                ++jumps;
            }
        }
        return INT_MAX;
    }
};