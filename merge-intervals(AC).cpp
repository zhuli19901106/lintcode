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
bool comp(const Interval &i1, const Interval &i2)
{
    if (i1.start != i2.start) {
        return i1.start < i2.start;
    } else {
        return i1.end < i2.end;
    }
}

class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> &a = intervals;
        sort(a.begin(), a.end(), comp);
        
        int n = a.size();
        if (n == 0) {
            return vector<Interval>();
        }
        int i, j;
        vector<Interval> ans;
        
        j = 0;
        ans.push_back(a[0]);
        for (i = 1; i < n; ++i) {
            if (a[i].start > ans[j].end) {
                ++j;
                ans.push_back(a[i]);
                continue;
            }
            ans[j].end = max(ans[j].end, a[i].end);
        }
        return ans;
    }
};