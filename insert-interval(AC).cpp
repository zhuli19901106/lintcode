#include <algorithm>
using namespace std;
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> &a = intervals;
        Interval b = newInterval;
        int i, n = a.size();
        
        vector<Interval> ans;
        i = 0;
        while (i < n && a[i].end < b.start) {
            ans.push_back(a[i++]);
        }
        while (i < n && b.end >= a[i].start) {
            b.start = min(b.start, a[i].start);
            b.end = max(b.end, a[i].end);
            ++i;
        }
        ans.push_back(b);
        while (i < n) {
            ans.push_back(a[i++]);
        }
        return ans;
    }
};