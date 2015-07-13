// The straight-forward solution
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        int i;
        for (i = 1; i < n; ++i) {
            ans = max(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};