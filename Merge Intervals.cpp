/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> re;
        if (intervals.empty()) {
            return re;
        }
        sort(intervals.begin(), intervals.end(), [](const Interval &x, const Interval &y)->bool{return x.start < y.start;});
        Interval tmp = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= tmp.end) {
                tmp.end = max(intervals[i].end, tmp.end);
            } else {
                re.push_back(tmp);
                tmp = intervals[i];
            }
        }
        re.push_back(tmp);
        return re;
    }
};