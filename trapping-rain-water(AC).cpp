#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        int n = heights.size();
        if (n == 0) {
            return 0;
        }
        vector<int> ll, rr;
        ll.resize(n);
        rr.resize(n);
        
        int i;
        int mx = 0;
        for (i = 0; i <= n - 1; ++i) {
            ll[i] = mx;
            mx = max(mx, heights[i]);
        }
        mx = 0;
        for (i = n - 1; i >= 0; --i) {
            rr[i] = mx;
            mx = max(mx, heights[i]);
        }
        
        int ans = 0;
        for (i = 0; i <= n - 1; ++i) {
            mx = max(0, min(ll[i], rr[i]) - heights[i]);
            ans += mx;
        }
        return ans;
    }
};