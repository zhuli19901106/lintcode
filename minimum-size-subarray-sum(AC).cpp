#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        
        int ll, rr;
        int sum;
        int ans = n + 1;
        
        sum = 0;
        ll = 0;
        rr = 0;
        while (rr < n) {
            sum += nums[rr];
            if (sum >= s) {
                ans = min(ans, rr - ll + 1);
                while (ll <= rr && sum - nums[ll] >= s) {
                    sum -= nums[ll];
                    ++ll;
                    ans = min(ans, rr - ll + 1);
                }
            }
            ++rr;
        }
        return ans <= n ? ans : -1;
    }
};