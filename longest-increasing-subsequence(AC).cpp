#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        vector<int> &a = nums;
        vector<int> v;
        int n = a.size();
        if (n == 0) {
            return 0;
        }
        v.push_back(a[0]);
        int i;
        for (i = 1; i < n; ++i) {
            if (a[i] >= v.back()) {
                v.push_back(a[i]);
                continue;
            }
            j = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[j] = a[i];
        }
        return v.size();
    }
};