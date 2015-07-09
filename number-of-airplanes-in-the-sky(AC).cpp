#include <algorithm>
#include <utility>
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
bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if (p1.first != p2.first) {
        return p1.first < p2.first;
    } else {
        return p1.second > p2.second;
    }
}

class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        vector<pair<int, int> > v;
        pair<int, int> p;
        int n = airplanes.size();
        int i;
        for (i = 0; i < n; ++i) {
            p.first = airplanes[i].start;
            p.second = 0;
            v.push_back(p);
            p.first = airplanes[i].end;
            p.second = 1;
            v.push_back(p);
        }
        sort(v.begin(), v.end(), comp);
        int ans = 0;
        int cnt = 0;
        n = v.size();
        for (i = 0; i < n; ++i) {
            if (v[i].second == 0) {
                ++cnt;
                ans = max(ans, cnt);
            } else {
                --cnt;
            }
        }
        return ans;
    }
};